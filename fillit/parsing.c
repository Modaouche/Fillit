/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:05:07 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/29 14:51:00 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>

static int		ft_nbtetris(char *tris, int i, int z, int y)
{
	while (tris[i] && (tris[i] == '\n' || tris[i] == '.' || tris[i] == '#'))
	{
		if (tris[i] == '\n')
		{
			if (((z != 4 && z != 0) && (y != 4 && y != 0)) || (y > 5)
					|| (y == 0 && z == -1))
				return (0);
			if (z == 4)
			{
				y++;
				z = -1;
			}
			else if (z == 0 || z == -1)
				y = 0;
			else
				return (0);
		}
		i++;
		if (!(tris[i] == '\n' && tris[i - 1] == '\n'))
			z++;
	}
	if (tris[i] || (tris[i - 1] == '\n' && tris[i - 2] == '\n'))
		return (0);
	return (1);
}

static int		ft_is_valid(char *buf, int p)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	buf[p] = '\0';
	while (buf[i])
	{
		if (buf[i] == '#' && buf[i + 1] && buf[i + 1] == '#')
			ok++;
		if (buf[i] == '#' && buf[i - 1] && buf[i - 1] == '#')
			ok++;
		if (buf[i] == '#' && buf[i + 5] && buf[i + 5] == '#')
			ok++;
		if (buf[i] == '#' && buf[i - 5] && buf[i - 5] == '#')
			ok++;
		i++;
	}
	if (ok == 6 || ok == 8)
		return (1);
	return (0);
}

static int		ft_nb_htg(char *buf)
{
	int i;
	int htg;
	int point;

	i = 0;
	htg = 0;
	point = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			htg++;
		else
			point++;
		i++;
	}
	if (htg != 4 || point != 15)
		return (0);
	return (1);
}

static char		**check_valid(char *tetris, int i, int p)
{
	char	**tab;
	char	buf[BUF_SIZE];

	while (tetris[i])
	{
		buf[p] = tetris[i];
		if ((tetris[i] == '\n' && tetris[i + 1] && tetris[i + 1] == '\n') ||
				(tetris[i] == '\n' && !tetris[i + 1]))
		{
			if (!(ft_is_valid(buf, p)) || !(ft_nb_htg(buf)))
				return(ft_freeparse(tetris));
			p = -1;
			i++;
		}
		p++;
		if (tetris[i])
			i++;
	}
	if (!(ft_is_valid(buf, p)) || !(ft_nb_htg(buf)))
		return(ft_freeparse(tetris));
	if (!(tab = ft_strsplit(tetris, '\n')))
		return (0);
	return (tab);
}

char			**ft_parsing(char *tetris)
{
	char		**tabtris;

	if ((ft_strlen(tetris)) > 545)
		return (0);
	if (!(ft_nbtetris(tetris, 0, 0, 0)) || !tetris[1])
		return (0);
	if (!(tabtris = check_valid(tetris, 0, 0)))
		return (0);
	return (tabtris);
}