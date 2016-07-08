/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:11:23 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/12 19:15:20 by mleconte         ###   ########.fr       */
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
			node->prev = it;
		}
		else
			*data = node;
	}
}

t_lst	*new_node(t_tet tetri)
{
	t_lst *node;

	node = ft_smalloc(sizeof(*node));
	node->t = tetri;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
