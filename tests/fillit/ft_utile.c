/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:02:46 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/07 17:37:15 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_check_top_bot(char **tab, int y, int x)
{
	if (y == 0)
		if (tab[y + 1][x] != '#')
			return (0);
	return (1);
}

int		ft_printris(char **map, int i)
{
	while (map[i])
		ft_putendl(map[i++]);
	return (1);
}

void	ft_reset(int *p, int *nbh)
{
	*nbh = 0;
	*p = 0;
}
