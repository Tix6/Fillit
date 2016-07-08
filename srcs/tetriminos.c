/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:24:29 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 21:05:50 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_pos		g_coords[19][3] = {
	{{.y = 1, .x = 0}, {.y = 0, .x = 1}, {.y = 1, .x = 1}},
	{{.y = 0, .x = 1}, {.y = 0, .x = 2}, {.y = 0, .x = 3}},
	{{.y = 1, .x = 0}, {.y = 2, .x = 0}, {.y = 3, .x = 0}},
	{{.y = -1, .x = 1}, {.y = 0, .x = 1}, {.y = 1, .x = 1}},
	{{.y = 1, .x = 0}, {.y = 2, .x = 0}, {.y = 1, .x = 1}},
	{{.y = 0, .x = 1}, {.y = 1, .x = 1}, {.y = 0, .x = 2}},
	{{.y = -1, .x = 1}, {.y = 0, .x = 1}, {.y = 0, .x = 2}},
	{{.y = 0, .x = 1}, {.y = -1, .x = 2}, {.y = 0, .x = 2}},
	{{.y = 0, .x = 1}, {.y = 1, .x = 1}, {.y = 2, .x = 1}},
	{{.y = 1, .x = 0}, {.y = 0, .x = 1}, {.y = 0, .x = 2}},
	{{.y = 1, .x = 0}, {.y = 2, .x = 0}, {.y = 2, .x = 1}},
	{{.y = 0, .x = 1}, {.y = 0, .x = 2}, {.y = 1, .x = 2}},
	{{.y = 1, .x = 0}, {.y = 2, .x = 0}, {.y = 0, .x = 1}},
	{{.y = 1, .x = 0}, {.y = 1, .x = 1}, {.y = 1, .x = 2}},
	{{.y = -2, .x = 1}, {.y = -1, .x = 1}, {.y = 0, .x = 1}},
	{{.y = 1, .x = 0}, {.y = -1, .x = 1}, {.y = 0, .x = 1}},
	{{.y = 0, .x = 1}, {.y = 1, .x = 1}, {.y = 1, .x = 2}},
	{{.y = 1, .x = 0}, {.y = 1, .x = 1}, {.y = 2, .x = 1}},
	{{.y = -1, .x = 1}, {.y = 0, .x = 1}, {.y = -1, .x = 2}}
};

static char const	*g_shapes[20] = {
	"##..##",
	"#...#...#...#",
	"####",
	"#..###",
	"###..#",
	"#...##..#",
	"#..##...#",
	"#...#..##",
	"#...###",
	"##..#...#",
	"###...#",
	"#...#...##",
	"###.#",
	"##...#...#",
	"#.###",
	"##.##",
	"#...##...#",
	"##...##",
	"#..##..#",
	NULL
};

static char			*stringify_tetriminos(char **arr)
{
	char *str;

	str = (char *)ft_smalloc(sizeof(char) * 17);
	ft_memset((void *)str, 0x00, 17);
	while (arr && *arr)
	{
		str = ft_strcat(str, *arr);
		arr++;
	}
	return (ft_strdup(str));
}

t_tet				recognize_tetriminos(char **array)
{
	static char	id = 'A';
	t_tet		new_tetriminos;
	char		*stringified;
	int			index;

	index = 0;
	stringified = stringify_tetriminos(array);
	new_tetriminos = (t_tet){0, (t_pos){0, 0}, NULL};
	while (g_shapes[index])
	{
		if (ft_strstr(stringified, g_shapes[index]))
		{
			new_tetriminos.char_id = id++;
			new_tetriminos.vector = g_coords[index];
			break ;
		}
		index++;
	}
	ft_strdel(&stringified);
	return (new_tetriminos);
}
