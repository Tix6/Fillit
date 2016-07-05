/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:06:37 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:31:16 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void print_tet(t_lst *tet)
{
	while (tet)
	{
		printf("[%d] %s\n", tet->id, shapes[tet->shape]);
		tet = tet->next;
	}
}

int	main(int ac, const char *av[])
{
	t_lst   *tetriminos;

	tetriminos = NULL;
	if (ac != 2 || !parse_input_file(av[1], &tetriminos))
		return (write(1, "Error\n", 6));
	printf("%d tetriminos\n", list_len(tetriminos));
	print_tet(tetriminos);
	return (fillit(tetriminos));
}
