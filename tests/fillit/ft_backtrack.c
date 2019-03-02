/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:38:31 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/29 14:54:39 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static void		ft_clean_map(char **map, char c, int y, int x)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

static int		ft_valid(t_list *listus, char **map, int x, int y)
{
	char		c;
	int			n;
	int			p;

	n = 0;
	p = 0;
	c = listus->letter;
	while (p <= 3)
	{
		if (map[y + listus->pos[p][0]] &&
			map[y + listus->pos[p][0]][x + listus->pos[p][1]] &&
			map[y + listus->pos[p][0]][x + listus->pos[p][1]] == '.')
			n++;
		else
			break ;
		p++;
	}
	if (n == 4)
	{
		while (n--)
			map[y + listus->pos[n][0]][x + listus->pos[n][1]] = c;
		p = 0;
		return (1);
	}
	return (0);
}

static int		ft_backtrack(t_list *listus, char **map, int x, int y)
{
	int			p;
	int			i;
	t_list		*tmp;

	tmp = listus;
	p = 0;
	i = 0;
	if (!tmp->next)
		return (ft_printris(map, i));
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_valid(tmp, map, x++, y))
			{
				i = ft_backtrack(tmp->next, map, 0, 0);
				if (i == 1)
					return (1);
			}
			ft_clean_map(map, listus->letter, 0, 0);
		}
		y++;
	}
	return (0);
}

int				ft_preback(t_list *listus, int i, int j)
{
	char		**map;

	while (i < 12 && listus->letter)
	{
		if (!(map = (char **)malloc(sizeof(char *) * (i + 2))))
			return (ft_tofree(map, 0, 0, 1));
		map[i + 1] = NULL;
		j = 0;
		while (j <= i)
		{
			if (!(map[j] = (char *)malloc(sizeof(char) * (i + 1))))
				return (ft_tofree(map, 0, 0, 1));
			ft_memset((void *)map[j], '.', i + 1);
			map[j][i + 1] = '\0';
			j++;
		}
		if (ft_backtrack(listus, map, 0, 0))
			return (ft_tofree(map, 0, 0, 0));
		i++;
	}
	return (1);
}
