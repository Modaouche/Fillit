/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharkati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:41 by yharkati          #+#    #+#             */
/*   Updated: 2018/05/07 17:38:19 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# define BUF_SIZE 21

char		**ft_parsing(char *tetri);
t_list		*parsing_minus(char **tab, int x, t_list *listus, int i);
int			ft_preback(t_list *listus, int i, int j);
int			ft_check_top_bot(char **tab, int y, int x);
int			ft_tofree(char **tab, char *buf, t_list **listus, int x);
void		ft_reset(int *p, int *nbh);
int			ft_printris(char **map, int i);
char		**ft_tofreetab(char **tab);
char        **ft_freeparse(char *tetris);
#endif
