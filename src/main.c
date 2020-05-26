/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:22:54 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/16 17:30:40 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetris	*head;
	char		**map;
	int			fd;
	int			nbr;
	int			time;

	head = NULL;
	nbr = 0;
	time = ac == 3 ? ft_atoi(av[ac - 1]): 0;
	time < 0 ? time = 0 : 0;
	if (ac == 2 || ac == 3)
	{
		fd = open(av[1], O_RDONLY);
		head = ft_read(fd, head);
		ft_after_read(head);
		nbr = ft_cnt_map(head);
		map = ft_make_map(nbr);
		ft_back_track(head, head, map, nbr, time);
	}
	else
		ft_putstr("usage : ./fillit [file_input] [slow time millisecond]\n");
	return (0);
}

void		ft_after_read(t_tetris *head)
{
	t_tetris	*temp;
	int			cnt;

	temp = head;
	cnt = 0;
	while (temp)
	{
		ft_check_valid(temp, head, 0, 0);
		ft_min_y_x(temp);
		ft_move(temp);
		ft_max_y_x(temp);
		ft_new_position(temp);
		temp->chr = 'A' + cnt;
		temp = temp->next;
		cnt++;
	}
	if (cnt > 26)
		ft_free_node_error(head);
}

t_tetris	*ft_read(const int fd, t_tetris *head)
{
	char	*line;
	char	*str;
	char	*tmp;
	char	*tmpl;

	str = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_strlen(line) == 0 || ft_strlen(line) == 4) || str[0] == '\n')
		{
			free(line);
			close(fd);
			ft_free_str(str);
		}
		tmpl = line;
		if (line[0] == '\0')
			line = "\n";
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(tmpl);
	}
	close(fd);
	ft_check_str(str, 0, 0);
	return (ft_str_to_node(str, head));
}
