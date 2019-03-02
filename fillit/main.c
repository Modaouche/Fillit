/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharkati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:37:28 by yharkati          #+#    #+#             */
/*   Updated: 2018/05/29 15:48:01 by yharkati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <string.h>

static int		ft_usage(char button)
{
	if (button == 1)
	{
		write(1, "usage : ./fillit [your_file]\n\t", 30);
		write(1, "[Only one valid file with 26 tetriminos maximum]\n", 50);
	}
	else
		ft_putendl("error");
	return (0);
}

static char		*ft_minos(int fd, char *buf, char *tmp, char *i)
{
	int			ret;

	if ((ret = read(fd, buf, BUF_SIZE)))
		buf[ret] = '\0';
	while (ret && (ret = read(fd, tmp, BUF_SIZE)))
	{
		tmp[ret] = '\0';
		i = buf;
		if (ret > 0)
			buf = ft_strjoin(buf, tmp);
		free(i);
	}
	return (buf);
}

int				main(int ac, char **av)
{
	int			fd;
	char		**tabtris;
	char		*tmp;
	char		*buf;
	t_list		*listus;

	if (ac != 2)
		return (ft_usage(1));
	if ((fd = open(av[1], O_RDWR)) == -1)
		return (ft_usage(0));
	if (!(buf = ft_strnew(BUF_SIZE + 1)))
		return (0);
	if (!(tmp = ft_strnew(BUF_SIZE + 1)))
		return (0);
	buf = ft_minos(fd, buf, tmp, 0);
	if (close(fd) == -1)
		return (1);
	tabtris = ft_parsing(buf);
	if (!(listus = ft_lstnew()))
		return (ft_tofree(tabtris, buf, &listus, 0));
	if (tabtris && (listus = parsing_minus(tabtris, 0, listus, 0)))
		ft_preback(listus, ft_sqrt(4 * (ft_lstlen(listus))), 0);
	else
		return (ft_tofree(tabtris, buf, &listus, 1));
	return (ft_tofree(tabtris, buf, &listus, 0));
}
