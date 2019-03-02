/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:36:16 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/10 13:09:36 by yharkati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (nb < 35)
		return (0);
	else if (nb < 45)
		return (5);
	else if (nb < 47)
		return (6);
	while (nbr < nb - 4)
	{
		nbr = i * i;
		i++;
	}
	return (i - 1);
}
