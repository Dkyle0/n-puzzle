/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 03:42:55 by val               #+#    #+#             */
/*   Updated: 2021/05/23 10:22:15 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	is_loop2(t_list *list0, t_list *list, t_all *all)
{
	map_copy(all->i_all, all->tmp_map, all->len);
	while (list != list0)
	{
		move_next(all->tmp_map, list);
		list = list->next;
	}
	move_next(all->tmp_map, list);
	if (compare_map(all->tmp_map, all->map, all->len))
	{
		return (1);
	}
	return (0);
}

void	del_list(t_list *list0, t_all *all)
{
	t_list	*list;

	if (all->free_list)
	{
		list = list0;
		while (list->next)
		{
			list = list->next;
		}
		list->next = all->free_list;
	}
	all->free_list = list0;
}

void	del_loop(t_all *all)
{
	t_list	*list;

	list = all->present_move;
	move_prev(all->map, list);
	list->move_weight[list->ii_min_weight] = INVALID_INDEX;
	list->ii_min_weight = find_min_weight(list->move_weight);
	if (list->ii_min_weight == INVALID_INDEX)
	{
		del_list(list, all);
		list = list->prev;
		all->present_move = list;
		(all->moves_num)--;
		if (list)
		{
			list->next = NULL;
			del_loop(all);
		}
	}
	else
	{
		list->i_b = list->i_move[list->ii_min_weight];
		move_next(all->map, list);
		all->i_zero = all->present_move->i_b;
	}
}

int	is_loop(t_list *list0, t_list *list, t_all *all)
{
	while (list0 != list)
	{
		if (list0->i_zero == list->i_zero && list0->i_b == list->i_b)
		{
			if (is_loop2(list0, all->head, all))
			{
				del_loop(all);
				return (EXIT_FAILURE);
			}
		}
		list0 = list0->next;
	}
	return (EXIT_SUCCESS);
}
