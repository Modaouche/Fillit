/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:33:50 by modaouch          #+#    #+#             */
/*   Updated: 2018/04/21 02:28:28 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_params(int ac, char *av[])
{
	int		i;
	int		j;

	j = 0;
	while (j < (ac - 1))
	{
		i = 1;
		while (i < (ac - 1))
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				ft_swap(&av[i], &av[i + 1]);
			}
			i++;
		}
		j++;
	}
	ft_print_params(av);
}
