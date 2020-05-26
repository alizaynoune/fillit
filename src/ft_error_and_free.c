/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:42:40 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/12 00:46:45 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_str(char *str)
{
	free(str);
	ft_putstr("error\n");
	exit(0);
}

void	ft_free_node_error(t_tetris *head)
{
	t_tetris *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	ft_putstr("error\n");
	exit(0);
}

void	ft_free_node_treu(t_tetris *head)
{
	t_tetris	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_free_map(char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
		free(map[cnt++]);
	free(map);
	map = NULL;
}
