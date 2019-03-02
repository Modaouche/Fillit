/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:18:47 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/07 16:52:05 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void		ft_position(int p, int x, t_list **listus, int *i)
{
	(*listus)->pos[*i][0] = p;
	(*listus)->pos[*i][1] = x;
	*i += 1;
}

static void		ft_reposition(t_list **listus, int x, int y)
{
	while (x < (*listus)->pos[0][1] && x < (*listus)->pos[1][1]
			&& x < (*listus)->pos[2][1] && x < (*listus)->pos[3][1])
		x++;
	while (y < (*listus)->pos[0][0] && y < (*listus)->pos[1][0]
			&& y < (*listus)->pos[2][0] && y < (*listus)->pos[3][0])
		y++;
	(*listus)->pos[0][0] -= y;
	(*listus)->pos[0][1] -= x;
	(*listus)->pos[1][0] -= y;
	(*listus)->pos[1][1] -= x;
	(*listus)->pos[2][0] -= y;
	(*listus)->pos[2][1] -= x;
	(*listus)->pos[3][0] -= y;
	(*listus)->pos[3][1] -= x;
}

static int		next_minus(int *p, int *i, t_list **listus, int *n)
{
	t_list		*new;

	if (*i == 4)
	{
		if (!(new = ft_lstnew()))
			return (0);
		ft_reposition(listus, 0, 0);
		(*listus)->letter = 'A' + (*n);
		*n += 1;
		ft_lstadd_back(listus, new);
		*listus = (*listus)->next;
	}
	*i = 0;
	*p = 0;
	return (1);
}

t_list			*parsing_minus(char **tab, int x, t_list *listus, int i)
{
	int			p;
	int			nbtris;
	t_list		*tmp;
	int			y;

	y = 0;
	tmp = listus;
	p = 0;
	nbtris = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
			if (tab[y][x++] == '#')
				ft_position(p, x, &tmp, &i);
		y++;
		p++;
		if (p == 4)
			if (!(next_minus(&p, &i, &tmp, &nbtris)))
				return (tmp);
	}
	if (listus->letter)
		return (listus);
	return (0);
}
