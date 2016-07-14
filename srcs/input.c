/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:12:21 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/14 23:13:28 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_neighbors(char **array, int i, int j)
{
	int nb;

	nb = 0;
	if (array)
	{
		if (j + 1 <= 3 && array[i][j + 1] == '#')
			nb += 1;
		if (j - 1 >= 0 && array[i][j - 1] == '#')
			nb += 1;
		if (i + 1 <= 3 && array[i + 1][j] == '#')
			nb += 1;
		if (i - 1 >= 0 && array[i - 1][j] == '#')
			nb += 1;
	}
	return (nb);
}

static int	is_valid_chunk(char **array)
{
	int neighbors;
	int i;
	int j;

	neighbors = 0;
	i = 0;
	j = 0;
	if (array)
	{
		while (array[i])
		{
			while (array[i][j])
			{
				if (array[i][j] == '#')
					neighbors += check_neighbors(array, i, j);
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (neighbors >= 6);
}

static int	parse_input_chunk(char const *chunk, t_lst **data)
{
	static int	count = 0;
	char		**array;

	if (chunk && ft_strlen(chunk) == 20)
	{
		if (++count > 26)
			return (0);
		if (count_char(chunk, '#') != 4 ||
			count_char(chunk, '.') != 12 ||
			count_char(chunk, '\n') != 4)
			return (0);
		if (chunk[4] != '\n' || chunk[9] != '\n' ||
			chunk[14] != '\n' || chunk[19] != '\n')
			return (0);
		array = ft_strsplit(chunk, '\n');
		if (is_valid_chunk(array))
		{
			push_to_list(data, new_node(recognize_tetriminos(array)));
			ft_arrdel(&array);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int			parse_input_file(char const *file, t_lst **data)
{
	int		fd;
	int		r;
	char	buf[21];
	char	skip[1];

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while (1)
		{
			ft_memset((void *)buf, 0x00, 21);
			r = read(fd, buf, 20);
			if (r != 20 || !parse_input_chunk(buf, data))
				return (0);
			r = read(fd, skip, 1);
			if (r == 1 && *skip != '\n')
				return (0);
			if (r <= 0)
				break ;
		}
		close(fd);
		return (1);
	}
	return (0);
}
