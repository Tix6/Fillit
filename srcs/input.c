/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:12:21 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 19:42:47 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_neightbors(char **array, int i, int j)
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
	int neightbors;
	int i;
	int j;

	neightbors = 0;
	i = 0;
	j = 0;
	if (array)
	{
		while (array[i])
		{
			while (array[i][j])
			{
				if (array[i][j] == '#')
				neightbors += check_neightbors(array, i, j);
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (neightbors >= 6);
}

static int	parse_input_chunk(char const *chunk, t_lst **data)
{
	static int	count = -1;
	char 		**array;

	if (count < 26 && chunk && ft_strlen(chunk) == 20)
	{
		count++;
		if (count_char(chunk, '#') != 4 ||
			count_char(chunk, '.') != 12 ||
			count_char(chunk, '\n') != 4)
			return (0);
		if (chunk[4] != '\n' || chunk[9] != '\n' ||
			chunk[14] != '\n' || chunk[19] != '\n')
			return (0);
		array = ft_strsplit(chunk, '\n');
		// think about freeing array
		if (is_valid_chunk(array))
		{
			push_to_list(data, new_node(recognize_tetriminos(array), count + 'A'));
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

int parse_input_file(char const *file, t_lst **data)
{
	int		fd;
	int		ret;
	char	buf[21];
	char	skip[1];

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while (1)
		{
			ft_memset((void *)buf, 0x00, 21);
			ret = read(fd, buf, 20);
			ft_putstr_fd(buf, 2);
			ft_putchar('\n');
			if (ret != 20 || !parse_input_chunk(buf, data))
				return (0);
			ret = read(fd, skip, 1);
			if (ret == 1 && *skip != '\n')
				return (0);
			if (ret <= 0)
				break ;
		}
		close(fd);
	}
	return (1);
}
