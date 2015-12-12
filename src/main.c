/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:06:37 by mleconte          #+#    #+#             */
/*   Updated: 2015/12/12 20:06:21 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, const char *av[])
{
	t_lst   *tetriminos;
	char    **square;

	tetriminos = NULL;
	if (ac != 2 || !parse_input_file(av[1], &tetriminos))
		write(1, "Error\n", 6);
	// while (tetriminos)
	// {
	// 	printf("%s\n", shapes[tetriminos->shape]);
	// 	tetriminos = tetriminos->next;
	// }
	return (0);
}
