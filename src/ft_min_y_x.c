/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_y_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:04:07 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/12 17:38:02 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_min_y_x(t_tetris *temp)
{
	int	min_y;
	int min_x;

	min_y = 0;
	min_x = 0;
	min_y = (temp->p_s[0].y > temp->p_s[1].y) ? temp->p_s[1].y : temp->p_s[0].y;
	min_y = (min_y > temp->p_s[2].y) ? temp->p_s[2].y : min_y;
	min_y = (min_y > temp->p_s[3].y) ? temp->p_s[3].y : min_y;
	temp->min_y = min_y;
	min_x = (temp->p_s[0].x > temp->p_s[1].x) ? temp->p_s[1].x : temp->p_s[0].x;
	min_x = (min_x > temp->p_s[2].x) ? temp->p_s[2].x : min_x;
	min_x = (min_x > temp->p_s[3].x) ? temp->p_s[3].x : min_x;
	temp->min_x = min_x;
}

void	ft_max_y_x(t_tetris *temp)
{
	int max_y;
	int max_x;

	max_y = 0;
	max_x = 0;
	max_y = (temp->p_s[0].y < temp->p_s[1].y) ? temp->p_s[1].y : temp->p_s[0].y;
	max_y = (max_y < temp->p_s[2].y) ? temp->p_s[2].y : max_y;
	max_y = (max_y < temp->p_s[3].y) ? temp->p_s[3].y : max_y;
	temp->max_y = max_y;
	temp->nmax_y = max_y;
	max_x = (temp->p_s[0].x < temp->p_s[1].x) ? temp->p_s[1].x : temp->p_s[0].x;
	max_x = (max_x < temp->p_s[2].x) ? temp->p_s[2].x : max_x;
	max_x = (max_x < temp->p_s[3].x) ? temp->p_s[3].x : max_x;
	temp->max_x = max_x;
	temp->nmax_x = max_x;
}

void	ft_new_position(t_tetris *temp)
{
	int	cnt;

	cnt = 0;
	while (cnt < 4)
	{
		temp->np_s[cnt].nx = temp->p_s[cnt].x;
		temp->np_s[cnt].ny = temp->p_s[cnt].y;
		cnt++;
	}
}

void	ft_move(t_tetris *temp)
{
	int cnt;

	cnt = 0;
	while (cnt < 4)
	{
		temp->tab[temp->p_s[cnt].y][temp->p_s[cnt].x] = '.';
		temp->p_s[cnt].y = temp->p_s[cnt].y - temp->min_y;
		temp->p_s[cnt].x = temp->p_s[cnt].x - temp->min_x;
		temp->tab[temp->p_s[cnt].y][temp->p_s[cnt].x] = '#';
		cnt++;
	}
}
