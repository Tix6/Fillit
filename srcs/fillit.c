/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:01:09 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 21:33:42 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			g_square[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE];

static void		s_print_square(size_t sides_length)
{
	size_t i;

	i = 0;
	while (i < sides_length)
	{
		write(STDOUT_FILENO, g_square[i], sides_length);
		ft_putchar(0x0a);
		i++;
	}
}

static size_t	s_square_root(size_t n)
{
	size_t ret;

	ret = 2;
	while ((ret * ret) < n)
		ret++;
	return (ret);
}

static void		s_init_square(t_lst *list, size_t sides_length)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (x < sides_length)
	{
		while (y < sides_length)
		{
			g_square[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	while (list)
	{
		list->t.pos = (t_pos){0, 0};
		list = list->next;
	}
}

int				fillit(t_lst *tetriminos)
{
	size_t square_size;
	size_t blocks_count;

	blocks_count = (list_len(tetriminos) * 4);
	square_size = s_square_root(blocks_count);
	s_init_square(tetriminos, square_size);
	while (!fill(tetriminos, square_size))
	{
		square_size += 1;
		s_init_square(tetriminos, square_size);
	}
	s_print_square(square_size);
	return (0);
}
