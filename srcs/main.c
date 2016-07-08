/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:06:37 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 20:46:30 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, const char *av[])
{
	t_lst *tetriminos;

	tetriminos = NULL;
	if (ac != 2 || !parse_input_file(av[1], &tetriminos))
		err_exit("error");
	return (fillit(tetriminos));
}
