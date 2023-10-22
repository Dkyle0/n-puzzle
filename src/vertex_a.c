/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:05:10 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:28:23 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	vertex_a0(t_list_a *open_list, t_all *all)
{
	if (open_list->h > all->h_max)
		all->h_max = open_list->h;
	if (open_list->h > all->h_min && open_list->h
		<= (all->h_max - (all->h_max / 35) - 3))
	{
		all->h_min = open_list->h;
		all->h_count = 1;
	}
	else if (open_list->h == all->h_min)
		(all->h_count)++;
	if (open_list->h >= (open_list->f / 3) && open_list->g > 5)
		all->skip = 1;
	else if (open_list->g <= 5)
		all->skip = 0;
}

static void	vertex_a1(t_list_a *open_list)
{
	if (open_list->prev)
	{
		if (open_list->prev->i_zero == open_list->i_move[UP_MOVEMENT])
			open_list->i_move[UP_MOVEMENT] = INVALID_INDEX;
		else if (open_list->prev->i_zero == open_list->i_move[RIGHT_MOVEMENT])
			open_list->i_move[RIGHT_MOVEMENT] = INVALID_INDEX;
		else if (open_list->prev->i_zero == open_list->i_move[DOWN_MOVEMENT])
			open_list->i_move[DOWN_MOVEMENT] = INVALID_INDEX;
		else if (open_list->prev->i_zero == open_list->i_move[LEFT_MOVEMENT])
			open_list->i_move[LEFT_MOVEMENT] = INVALID_INDEX;
	}
}

static void	vertex_a3(t_list_a *list, t_all *all)
{
	(all->compl_time)++;
	if (all->type_alg != UNIFORM)
	{
		list->g = summ_h(all, all->type_heuristic);
		list->f = list->g + list->h;
	}
	list->f = list->g + list->h;
	add_el_to_queue(list, all);
}

static int	vertex_a2(t_list_a *open_list, int index, t_all *all)
{
	t_list_a	*list;

	if (open_list->i_move[index] != INVALID_INDEX)
	{
		list = create_list_a(all->i_zero, open_list->i_move[index],
				open_list, all);
		if (!(list))
			return (EXIT_FAILURE);
		if (list_in_open_list(list, all))
		{
			list->right = all->free_list_a;
			all->free_list_a = list;
		}
		else
		{
			vertex_a3(list, all);
		}
	}
	return (EXIT_SUCCESS);
}

int	vertex_a(t_list_a *open_list, t_all *all)
{
	if (all->type_alg == IDA)
	{
		vertex_a0(open_list, all);
		if (all->skip && all->h_count >= H_LIM && open_list->h <= all->h_min)
		{
			open_list = extract_top_a(all);
			open_list->right = all->free_list_a;
			all->free_list_a = open_list;
			return (EXIT_SUCCESS);
		}
	}
	find_possible_moves(open_list->i_zero, open_list->i_move, all);
	vertex_a1(open_list);
	if (vertex_a2(open_list, UP_MOVEMENT, all)
		|| vertex_a2(open_list, RIGHT_MOVEMENT, all)
		|| vertex_a2(open_list, DOWN_MOVEMENT, all)
		|| vertex_a2(open_list, LEFT_MOVEMENT, all))
		return (EXIT_FAILURE);
	vertex_a_end(open_list, all);
	return (EXIT_SUCCESS);
}
