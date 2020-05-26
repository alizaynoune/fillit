/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:15:48 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/12 18:22:23 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_cnt_map(t_tetris *head)
{
	t_tetris	*temp;
	int			cnt;
	int			nbr;

	temp = head;
	cnt = 0;
	nbr = 0;
	while (temp)
	{
		temp = temp->next;
		cnt++;
	}
	while (nbr <= 46340)
	{
		if (nbr * nbr >= cnt * 4)
			return (nbr);
		nbr++;
	}
	return (0);
}

char	**ft_make_map(int nbr)
{
	char	**map;
	int		cnt;
	int		cntstr;

	cnt = 0;
	cntstr = 0;
	if (!(map = (char **)malloc(sizeof(char *) * nbr + 1)))
		return (NULL);
	map[nbr] = NULL;
	while (cnt < nbr)
	{
		if (!(map[cnt] = (char *)malloc(sizeof(char) * nbr + 1)))
			return (NULL);
		map[cnt][nbr] = '\0';
		cntstr = 0;
		while (cntstr < nbr)
			map[cnt][cntstr++] = '.';
		cnt++;
	}
	return (map);
}

int		ft_safe_place(char **map, t_tetris *temp, int nbr)
{
	int	cnt;

	cnt = 0;
	if (temp->nmax_y >= nbr || temp->nmax_x >= nbr)
		return (0);
	while (cnt < 4)
	{
		if (map[temp->np_s[cnt].ny][temp->np_s[cnt].nx] != '.')
			return (0);
		cnt++;
	}
	return (1);
}

int		ft_move_place(t_tetris *temp, int nbr)
{
	int	cnt;

	cnt = 0;
	if (temp->nmax_x + 1 < nbr)
	{
		while (cnt < 4)
			temp->np_s[cnt++].nx++;
		temp->nmax_x++;
		return (1);
	}
	else if (temp->nmax_y + 1 < nbr)
	{
		temp->nmax_x = temp->max_x;
		while (cnt < 4)
		{
			temp->np_s[cnt].nx = temp->p_s[cnt].x;
			cnt++;
		}
		cnt = 0;
		while (cnt < 4)
			temp->np_s[cnt++].ny++;
		temp->nmax_y++;
		return (1);
	}
	return (0);
}

int		ft_stock_to_map(char **map, t_tetris *temp, int nbr)
{
	int	cnt;

	cnt = 0;
	while (ft_safe_place(map, temp, nbr) == 0)
	{
		if (ft_move_place(temp, nbr) == 0)
			return (0);
	}
	while (cnt < 4)
	{
		map[temp->np_s[cnt].ny][temp->np_s[cnt].nx] = temp->chr;
		cnt++;
	}
	return (1);
}
