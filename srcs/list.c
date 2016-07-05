/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:11:23 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/06 17:01:01 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	push_to_list(t_lst **data, t_lst *node)
{
	t_lst *it;

	if (node)
	{
		if (*data)
		{
			it = *data;
			while (it->next)
				it = it->next;
			it->next = node;
		}
		else
			*data = node;
	}
}

t_lst	*new_node(int t, char c)
{
	t_lst *node;

	node = ft_smalloc(sizeof(*node));
	node->shape = t;
	node->ch = c;
	node->next = NULL;
	return (node);
}
