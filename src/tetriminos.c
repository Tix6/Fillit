/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:24:29 by mleconte          #+#    #+#             */
/*   Updated: 2015/12/12 19:47:50 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*stringify_tetriminos(char **arr)
{
	char *str;

	str = (char *)malloc(sizeof(17));
	bzero(str, 17);
	while (arr && *arr)
	{
		str = strcat(str, *arr);
		arr++;
	}
	return (strdup(str));
}

int			recognize_tetriminos(char **array)
{
	char *tetriminos;
	int index = 0;

	tetriminos = stringify_tetriminos(array);
	while (shapes[index])
	{
		if (strstr(tetriminos, shapes[index]))
		return (index);
		index++;
	}
	return (-1);
}
