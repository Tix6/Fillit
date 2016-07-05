/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:24:29 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 20:27:01 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*stringify_tetriminos(char **arr)
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

int			recognize_tetriminos(char **array)
{
	char *tetriminos;
	int index = 0;

	tetriminos = stringify_tetriminos(array);
	while (shapes[index])
	{
		if (ft_strstr(tetriminos, shapes[index]))
			return (index);
		index++;
	}
	err_exit("error");
	return (-1);
}
