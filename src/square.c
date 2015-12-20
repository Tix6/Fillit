/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:01:09 by mleconte          #+#    #+#             */
/*   Updated: 2015/12/20 21:16:20 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	square_root(int n)
{
	int ret;

	ret = 4;
	while ((ret * ret) < n)
		ret++;
	return (ret);
}

void	print_square(char **square)
{
	while (square && *square)
	{
		printf("%s\n", *square);
		square++;
	}
}

char		**init_square(int blocks)
{
	char	**square;
	char	*row;
	int		sqrt;
	int		i;
	int		len;

	i = 0;
	sqrt = square_root(blocks);
	len = sqrt * sqrt + sqrt;
	square = smalloc(sizeof(*square) * sqrt + 1);
	row = smalloc(len);
	bzero(row, len);
	while (i < sqrt)
	{
		square[i] = &row[i * sqrt + i];
		square[i] = memset((void *)square[i], '.', sqrt);
		i++;
	}
	square[i] = NULL;
	return (square);
}
