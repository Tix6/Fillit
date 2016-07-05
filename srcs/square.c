/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:01:09 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 17:16:42 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **square)
{
	while (square && *square)
	{
		ft_putendl(*square);
		square++;
	}
}

char		**init_square(size_t size)
{
	char	**square;
	char	*row;
	size_t	i;
	int		len;

	i = 0;
	len = size * size + size;
	square = ft_smalloc(sizeof(*square) * size + 1);
	row = ft_smalloc(len);
	ft_memset((void *)row, 0x00, len);
	while (i < size)
	{
		square[i] = &row[i * size + i];
		square[i] = ft_memset((void *)square[i], '.', size);
		i++;
	}
	square[i] = NULL;
	return (square);
}
