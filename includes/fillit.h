/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:18:47 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/16 20:57:50 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct		s_newps
{
	int				nx;
	int				ny;
}					t_newps;

typedef struct		s_tetris
{
	char			tab[4][5];
	char			chr;
	int				max_y;
	int				max_x;
	int				nmax_x;
	int				nmax_y;
	int				min_y;
	int				min_x;
	t_position		p_s[4];
	t_newps			np_s[4];
	struct s_tetris	*next;
	struct s_tetris *prev;
}					t_tetris;
t_tetris			*ft_read(const int fd, t_tetris *head);
void				ft_after_read(t_tetris *head);
void				ft_check_str(char *str, size_t cntline, size_t cntchar);
void				ft_check_valid(t_tetris *temp, t_tetris *head,
		int ctab, int vld);
t_tetris			*ft_add_new_node(t_tetris *head, t_tetris *new);
t_tetris			*ft_new_node(t_tetris *head, char *nstr,
		size_t cnt, size_t cnttab);
t_tetris			*ft_str_to_node(char *str, t_tetris *head);
void				ft_min_y_x(t_tetris *temp);
void				ft_max_y_x(t_tetris *temp);
void				ft_new_position(t_tetris *temp);
void				ft_move(t_tetris *temp);
int					ft_cnt_map(t_tetris *head);
char				**ft_make_map(int nbr);
int					ft_safe_place(char **map, t_tetris *temp, int nbr);
int					ft_move_place(t_tetris *temp, int nbr);
int					ft_stock_to_map(char **map, t_tetris *temp, int nbr);
void				ft_free_str(char *str);
void				ft_free_node_error(t_tetris *head);
void				ft_free_node_treu(t_tetris *head);
void				ft_free_map(char **map);
void				ft_rest_position(t_tetris *temp);
void				ft_clear_char(t_tetris *temp, char **map);
void				ft_back_track(t_tetris *head, t_tetris *temp,
		char **map, int nbr, int time);
void				ft_display(char **map, t_tetris *head);
#endif
