/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:06:37 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 20:27:06 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char const	*shapes[20] = {
	"##..##",           // | |
	"#...#...#...#", //  |
	"####",         //  -–
	"#..###",      //  !T
	"###..#",		//  T
	"#...##..#",
	"#..##...#",
	"#...#..##",   // J
	"#...###",
	"##..#...#",
	"###...#",
	"#...#...##",   // L
	"###.#",
	"##...#...#",
	"#.###",
	"##.##",       // S
	"#...##...#",
	"##...##",      // Z
	"#..##..#",
	NULL
};

void print_tet(t_lst *tet)
{
	while (tet)
	{
		printf("[%c] %s\n", tet->ch, shapes[tet->shape]);
		tet = tet->next;
	}
}

int	main(int ac, const char *av[])
{
	t_lst   *tetriminos;

	tetriminos = NULL;
	if (ac != 2 || !parse_input_file(av[1], &tetriminos))
		err_exit("error");
	printf("%d tetriminos\n", list_len(tetriminos));
	print_tet(tetriminos);
	return (fillit(tetriminos));
}
