/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:07:14 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 20:26:28 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_lst
{
	int             shape;
	char            ch;
	struct s_lst    *next;
}               t_lst;

typedef struct s_pos
{
	int x;
	int y;
}				t_pos;

extern char const	*shapes[20];

void	push_to_list(t_lst **data, t_lst *node);
t_lst	*new_node(int t, char c);

int		parse_input_file(char const *file, t_lst **data);
int		recognize_tetriminos(char **array);

int		count_char(char const *str, int c);
void	err_exit(char const *msg);
int		list_len(t_lst *list);

char	**init_square(size_t size);
void	print_square(char **square);

int 	fillit(t_lst *tetriminos);

#endif
