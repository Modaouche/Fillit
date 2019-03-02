/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:50:10 by modaouch          #+#    #+#             */
/*   Updated: 2018/05/07 17:06:55 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void)
{
	t_list	*list;

	if (!(list = malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	return (list);
}
