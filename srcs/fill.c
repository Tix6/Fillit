/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:11:01 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 20:26:15 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_pos		coords[19][3] = {
	{{.y = 1, .x = 0},	{.y = 0, .x = 1},	{.y = 1, .x = 1}},
	{{.y = 0, .x = 1},	{.y = 0, .x = 2},	{.y = 0, .x = 3}},
	{{.y = 1, .x = 0},	{.y = 2, .x = 0},	{.y = 3, .x = 0}},
	{{.y = -1, .x = 1},	{.y = 0, .x = 1},	{.y = 1, .x = 1}},
	{{.y = 1, .x = 0},	{.y = 2, .x = 0},	{.y = 1, .x = 1}},
	{{.y = 0, .x = 1},	{.y = 1, .x = 1},	{.y = 0, .x = 2}},
	{{.y = -1, .x = 1},	{.y = 0, .x = 1},	{.y = 0, .x = 2}},
	{{.y = 0, .x = 1},	{.y = -1, .x = 2},	{.y = 0, .x = 2}},
	{{.y = 0, .x = 1},	{.y = 1, .x = 1},	{.y = 2, .x = 1}},
	{{.y = 1, .x = 0},	{.y = 0, .x = 1},	{.y = 0, .x = 2}},
	{{.y = 1, .x = 0},	{.y = 2, .x = 0},	{.y = 1, .x = 2}},
	{{.y = 0, .x = 1},	{.y = 0, .x = 2},	{.y = 1, .x = 2}},
	{{.y = 1, .x = 0},	{.y = 2, .x = 0},	{.y = 0, .x = 1}},
	{{.y = 1, .x = 0},	{.y = 1, .x = 1},	{.y = 1, .x = 2}},
	{{.y = -2, .x = 1},	{.y = -1, .x = 1},	{.y = 0, .x = 1}},
	{{.y = 1, .x = 0},	{.y = -1, .x = 1},	{.y = 0, .x = 1}},
	{{.y = 0, .x = 1},	{.y = 1, .x = 1},	{.y = 1, .x = 2}},
	{{.y = 1, .x = 0},	{.y = 1, .x = 1},	{.y = 2, .x = 1}},
	{{.y = -1, .x = 1},	{.y = 0, .x = 1},	{.y = -1, .x = 2}}
};

static int s_try_one(t_pos *c, char **s, int x, int y)
{
	int x2 = x;
	int y2 = y;
	int i = 0;

	printf("%s x: %d y: %d\n", __func__,x, y);
	if (s[x2] && s[x2][y2])
	{
		if (s[x][y] != '.')
			return (0);
		while (i < 3)
		{
			x2 = x + c[i].x;
			y2 = y + c[i].y;
			// printf("x:%d y:%d x2:%d y2:%d\n", c[i].x, c[i].y, x2, y2);
			if (x2 < 0 || y2 < 0 || !s[x2] || !s[x2][y2] || s[x2][y2] != '.')
				return (0);
			// printf("square: %c\n", s[x2][y2]);
			i++;
		}
		return (1);
	}
	return (0);
}

static void s_fill_one(t_lst tetrimino, char **s, int x, int y)
{
	t_pos *c = coords[tetrimino.shape];

	// printf("filled: [%d][%d]%c [%d][%d]%c [%d][%d]%c --> %c\n", (x + c[0].x), (y + c[0].y),  s[x + c[0].x][y + c[0].y], (x + c[1].x), (y + c[1].y), s[x + c[1].x][y + c[1].y], (x + c[2].x), (y + c[2].y), s[x + c[2].x][y + c[2].y], tetrimino.ch);
	s[x][y] = tetrimino.ch;
	printf("%s x: %d y: %d char: %c\n", __func__, x, y, tetrimino.ch);
	s[x + c[0].x][y + c[0].y] = tetrimino.ch;
	s[x + c[1].x][y + c[1].y] = tetrimino.ch;
	s[x + c[2].x][y + c[2].y] = tetrimino.ch;
}

static int s_fill(t_lst *t, char **square)
{
	char **s;
	int x = 0;
	int y = 0;

	s = square;
	printf("%s\n", __func__);
	while (s[x])
	{
		while (s[x][y])
		{
			if (s_try_one(coords[t->shape], s, x, y))
			{
				s_fill_one(*t, s, x, y);
				t = t->next;
				x = 0;
				y = 0;
				if (!t)
					return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

static size_t	square_root(size_t n)
{
	size_t ret;

	ret = 2;
	while ((ret * ret) < n)
		ret++;
	return (ret);
}

int	fillit(t_lst *tetriminos)
{
	char	**square;
	size_t	size;

	square = NULL;
	if (tetriminos)
	{
		size = square_root(list_len(tetriminos) * 4);
		square = init_square(size);
		while (!s_fill(tetriminos, square))
		{
			size += 1;
			printf("FAILED square\n");
			print_square(square);
			ft_putchar('\n');
			printf("new square of %zu\n", size);
			// ft_arrdel(&square);
			square = init_square(size);
		}
		print_square(square);
	}
	else
	{
		ft_putstr_fd("no tetriminos", 2);
		return (-1);
	}
	return (0);
}
