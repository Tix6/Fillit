/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:07:14 by mleconte          #+#    #+#             */
/*   Updated: 2015/12/20 21:12:29 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>

typedef struct s_lst
{
	int             shape;
	char            id;
	struct s_lst    *next;
}               t_lst;

extern const char *shapes[20];

void	push_to_list(t_lst **data, t_lst *node);
t_lst	*new_node(int t, char c);

int		parse_input_file(char const *file, t_lst **data);
int		recognize_tetriminos(char **array);

char	**ft_strsplit(char const *s, char c);
int		count_char(char const *str, int c);
void	err_exit(char const *msg);
void	*smalloc(size_t len);
int		list_len(t_lst *list);

char	**init_square(int blocks);
void	print_square(char **square);

int 	fillit(t_lst *tetriminos);

# define ERR_MALLOC "ERR_MALLOC"

#endif
