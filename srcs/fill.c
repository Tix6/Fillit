/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:11:01 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:30:17 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fillit(t_lst *tetriminos)
{
	char    **square;

	if (tetriminos)
	{
		square = init_square(list_len(tetriminos) * 4);
		print_square(square);
	}
	else
	{
		ft_putstr_fd("no tetriminos", 2);
		return (-1);
	}
	return (0);
}
