/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 06:46:15 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/26 19:56:32 by yharkati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_tofree(char **tab, char *buf, t_list **listus, int x)
{
	int		i;

	i = 0;
	if (buf)
		free(buf);
	if (tab)
	{
		while (tab[i])
			i++;
		while (i)
			free(tab[i--]);
		free(tab[i]);
		free(tab);
	}
	if (listus && *listus)
		ft_lstdel(listus);
	if (x == 1)
		ft_putendl("error");
	return (0);
}
char		**ft_freeparse(char *tetris)
{
	if (tetris)
		free(tetris);
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

char		**ft_tofreetab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		while (i)
			free(tab[i--]);
		free(tab[i]);
		free(tab);
	}
	return (0);
}
