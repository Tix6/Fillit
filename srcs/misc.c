/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:13:46 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 17:06:45 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_char(char const *str, int c)
{
	if (*str)
		return (((*str == c) ? 1 : 0) + count_char(str + 1, c));
	else
		return (0);
}

void 	err_exit(char const *msg)
{
	ft_putendl_fd(msg, 2);
	exit(-1);
}

int		list_len(t_lst *list)
{
	return (list) ? 1 + list_len(list = list->next) : 0;
}
