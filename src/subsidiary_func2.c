/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary_func2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:44:47 by val               #+#    #+#             */
/*   Updated: 2021/05/23 02:45:12 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	move_len(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->prev;
		i++;
	}
	return (i);
}

void	connect_way(t_all *all)
{
	t_list_a	*list;

	list = all->open_list;
	if (list)
	{
		while (list->prev)
		{
			list->prev->next = list;
			list = list->prev;
		}
	}
}
