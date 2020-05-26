/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:47:20 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/18 23:58:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*color[26]=
		{	"\e[0;31mA"
			,"\e[0;32mB"
			,"\e[0;33mC"
			,"\e[0;34mD"
			,"\e[0;35mE"
			,"\e[0;36mF"
			,"\e[0;37mG"
			,"\e[1;30mH"
			,"\e[1;31mI"
			,"\e[1;32mJ"
			,"\e[1;33mK"
			,"\e[1;34mL"
			,"\e[1;35mM"
			,"\e[1;36mN"
			,"\e[1;37mO"
			,"\e[0;90mP"
			,"\e[0;91mQ"
			,"\e[0;92mR"
			,"\e[0;93mS"
			,"\e[0;94mT"
			,"\e[0;95mU"
			,"\e[0;96mV"
			,"\e[0;97mW"
			,"\e[1;90mX"
			,"\e[1;92mY"
			,"\e[1;93mZ"
		};

void	ft_display(char **map, t_tetris *head)
{
	int	cnt;
	int	cnt1;

	cnt = 0;
	if (head)
	while (map[cnt])
	{
		cnt1 = -1;
		while (map[cnt][++cnt1])
			map[cnt][cnt1] != '.' ?ft_putstr(color[map[cnt][cnt1] - 'A']): ft_putstr("\e[0m.");
		ft_putstr("\e[0m\n");
		cnt++;
	}
}
