/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_stock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:32:41 by alzaynou          #+#    #+#             */
/*   Updated: 2019/05/16 17:06:17 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_check_str(char *str, size_t cntline, size_t cntchar)
{
	size_t cnt;

	cnt = 0;
	if (str[0] == '\0')
		ft_free_str(str);
	while (str[cnt])
	{
		if (str[cnt] == '#')
			cntchar++;
		if (str[cnt] == '\n' && (str[cnt + 1] == '\n' || str[cnt + 1] == '\0'))
			ft_free_str(str);
		if (!(str[cnt] == '#' || str[cnt] == '.' || str[cnt] == '\n'))
			ft_free_str(str);
		if ((str[cnt] == '\n' && (cntline != 16 || cntchar != 4)) ||
				(str[cnt + 1] == '\0' && (cntline != 15 || cntchar != 4)))
			ft_free_str(str);
		cntline++;
		if (str[cnt] == '\n')
		{
			cntline = 0;
			cntchar = 0;
		}
		cnt++;
	}
}

void		ft_check_valid(t_tetris *temp, t_tetris *head, int ctab, int vld)
{
	size_t		cnt;
	size_t		pchar;

	pchar = 0;
	while (ctab < 4)
	{
		cnt = 0;
		while (cnt < 4)
		{
			if (temp->tab[ctab][cnt] == '#')
			{
				temp->p_s[pchar].x = cnt;
				temp->p_s[pchar++].y = ctab;
			}
			if (temp->tab[ctab][cnt] == '#' && temp->tab[ctab][cnt + 1] == '#')
				vld++;
			if (ctab < 3 && (temp->tab[ctab][cnt] == '#' &&
						temp->tab[ctab + 1][cnt] == '#'))
				vld++;
			cnt++;
		}
		ctab++;
	}
	if (!(vld == 3 || vld == 4))
		ft_free_node_error(head);
}

t_tetris	*ft_add_new_node(t_tetris *head, t_tetris *new)
{
	t_tetris *temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (head);
}

t_tetris	*ft_new_node(t_tetris *head, char *nstr, size_t cnt, size_t cnttab)
{
	t_tetris	*new;
	size_t		cntstr;

	cntstr = 0;
	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	while (nstr[cnt])
	{
		new->tab[cnttab][cntstr++] = nstr[cnt++];
		if (cnt > 0 && (cnt % 4 == 0))
		{
			new->tab[cnttab++][cntstr] = '\0';
			cntstr = 0;
		}
	}
	new->next = NULL;
	new->prev = NULL;
	if (head == NULL)
		return (new);
	return (ft_add_new_node(head, new));
}

t_tetris	*ft_str_to_node(char *str, t_tetris *head)
{
	size_t		frst;
	size_t		lst;
	size_t		nlst;
	char		*nstr;

	frst = 0;
	lst = 0;
	while (str[lst])
	{
		if (str[lst] == '\n' || str[lst + 1] == '\0')
		{
			nlst = str[lst] == '\n' ? lst - frst : lst - frst + 1;
			nstr = ft_strsub(str, frst, nlst);
			head = ft_new_node(head, nstr, 0, 0);
			free(nstr);
			frst = lst + 1;
		}
		lst++;
	}
	free(str);
	return (head);
}
