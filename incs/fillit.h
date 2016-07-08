/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:07:14 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 20:58:03 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tet
{
	char			char_id;
	t_pos			pos;
	t_pos			*vector;
}					t_tet;

typedef struct		s_lst
{
	t_tet			t;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

# define MAX_SQUARE_SIZE 16

extern char			g_square[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE];

int					parse_input_file(char const *file, t_lst **data);
void				push_to_list(t_lst **data, t_lst *node);
t_lst				*new_node(t_tet tetri);
t_tet				recognize_tetriminos(char **array);
int					count_char(char const *str, int c);
void				err_exit(char const *msg);
int					list_len(t_lst *list);
int					fillit(t_lst *tetriminos);
int					fill(t_lst *list, size_t sides_length);

#endif
