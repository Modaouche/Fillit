/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:15:33 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/01 17:18:56 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst)
{
	t_list	*list;

	list = *alst;
	while (*alst)
	{
		list = *alst;
		*alst = (*alst)->next;
		free(list);
	}
	list = NULL;
	*alst = NULL;
}
