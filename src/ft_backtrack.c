/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:20:39 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/19 00:04:49 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_rest_position(t_tetris *temp)
{
	int	cnt;

	cnt = 0;
	while (cnt < 4)
	{
		temp->np_s[cnt].nx = temp->p_s[cnt].x;
		temp->np_s[cnt].ny = temp->p_s[cnt].y;
		cnt++;
	}
	temp->nmax_x = temp->max_x;
	temp->nmax_y = temp->max_y;
}

void	ft_clear_char(t_tetris *temp, char **map)
{
	int	cnt;

	cnt = 0;
	if (temp)
	{
		while (cnt < 4)
		{
			map[temp->np_s[cnt].ny][temp->np_s[cnt].nx] = '.';
			cnt++;
		}
	}
}

void	ft_back_track(t_tetris *head, t_tetris *temp, char **map, int nbr, int time)
{
	while (temp)
	{
		if ((ft_stock_to_map(map, temp, nbr)) == 0)
		{
			ft_rest_position(temp);
			temp = temp->prev;
			ft_clear_char(temp, map);
			while (temp && (ft_move_place(temp, nbr)) == 0)
			{
				ft_rest_position(temp);
				temp = temp->prev;
				ft_clear_char(temp, map);
			}
			if (temp == NULL)
			{
				ft_free_map(map);
				map = ft_make_map(++nbr);
				temp = head;
			}
		}
		else
			temp = temp->next;
		if (time)
		{
			usleep(time);
			system("clear");
			ft_display(map, head);
		}
	}
	system("clear");
	ft_display(map, head);
	ft_free_map(map);
	ft_free_node_treu(head);
}
