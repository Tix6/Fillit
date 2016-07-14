/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:11:01 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 23:01:11 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		s_try_one(t_tet t)
{
	t_pos	*v;
	int		x2;
	int		y2;
	int		i;

	v = t.vector;
	x2 = 0;
	y2 = 0;
	i = 0;
	if (g_square[t.pos.x][t.pos.y] != '.')
		return (0);
	while (i < 3)
	{
		x2 = t.pos.x + v[i].x;
		y2 = t.pos.y + v[i].y;
		if (x2 < 0 || y2 < 0 || !g_square[x2] || !g_square[x2][y2] ||
			g_square[x2][y2] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void		s_clear_one(t_tet *t)
{
	t_pos	*v;
	int		x;
	int		y;

	v = t->vector;
	x = t->pos.x;
	y = t->pos.y;
	g_square[t->pos.x][t->pos.y] = '.';
	g_square[x + v[0].x][y + v[0].y] = '.';
	g_square[x + v[1].x][y + v[1].y] = '.';
	g_square[x + v[2].x][y + v[2].y] = '.';
}

static void		s_fill_one(t_tet *t)
{
	t_pos	*v;
	int		x;
	int		y;

	v = t->vector;
	x = t->pos.x;
	y = t->pos.y;
	g_square[x][y] = t->char_id;
	g_square[x + v[0].x][y + v[0].y] = t->char_id;
	g_square[x + v[1].x][y + v[1].y] = t->char_id;
	g_square[x + v[2].x][y + v[2].y] = t->char_id;
}

static t_pos	s_find_next_pos(t_pos p, int sides_length)
{
	int x;
	int y;

	x = p.x;
	y = p.y;
	if (y < sides_length - 1)
		return ((t_pos){x, y + 1});
	else
		return ((t_pos){x + 1, 0});
}

int				fill(t_lst *list, size_t sides_length)
{
	while (list)
	{
		if (s_try_one(list->t))
		{
			s_fill_one(&list->t);
			if (list->next == NULL)
				return (1);
			list = list->next;
			list->t.pos = (t_pos){0, 0};
		}
		else
		{
			list->t.pos = s_find_next_pos(list->t.pos, sides_length);
			if (list->t.pos.x >= (int)sides_length)
			{
				if (list->prev == NULL)
					return (0);
				list = list->prev;
				s_clear_one(&list->t);
				list->t.pos = s_find_next_pos(list->t.pos, sides_length);
			}
		}
	}
	return (1);
}
