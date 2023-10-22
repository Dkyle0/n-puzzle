/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_hopping_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:03:22 by val               #+#    #+#             */
/*   Updated: 2021/05/23 19:42:42 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	greedy_hopping_algorithm3(t_all *all)
{
	(all->compl_size)++;
	all->start_time = SDL_GetTicks();
	if (all->type_alg == GREEDY_JUMP)
	{
		if (vertex_jump(all->present_move, all, DEEP_LEN, NULL))
			return (closer(all, "Failed to create list!\nN-puzzle", 4 | 1));
	}
	else if (all->type_alg == GREEDY)
	{
		if (vertex_jump(all->present_move, all, 0, NULL))
			return (closer(all, "Failed to create list!\nN-puzzle", 4 | 1));
	}
	if (is_loop(all->head, all->present_move, all))
	{
		if (!(all->present_move))
		{
			all->head = NULL;
			return (closer(all,
					"Can't find a path that doesn't end up looping!\n", 1));
		}
	}
	all->end_time = SDL_GetTicks();
	all->pr_time += (all->end_time - all->start_time);
	all->moves_num = move_len(all->present_move);
	return (EXIT_SUCCESS);
}

int	greedy_hopping_algorithm2(t_all *all)
{
	(all->compl_size)++;
	all->start_time = SDL_GetTicks();
	if (all->type_alg == GREEDY_JUMP)
	{
		if (vertex_jump(NULL, all, DEEP_LEN, NULL))
			return (closer(all, "Failed to create list!\nN-puzzle", 4 | 1));
	}
	else if (all->type_alg == GREEDY)
	{
		if (vertex_jump(NULL, all, 0, NULL))
			return (closer(all, "Failed to create list!\nN-puzzle", 4 | 1));
	}
	all->end_time = SDL_GetTicks();
	all->pr_time += (all->end_time - all->start_time);
	all->head = all->present_move;
	if (!(all->user_exit) && window(all))
	{
		if (closer(all, NULL, 3) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	greedy_hopping_algorithm(t_all *all)
{
	if (!(compare_map(all->map, all->def_map, all->len)))
	{
		if (greedy_hopping_algorithm2(all))
			return (EXIT_FAILURE);
		while (!(compare_map(all->map, all->def_map, all->len)))
		{
			if (greedy_hopping_algorithm3(all))
				return (EXIT_FAILURE);
			if (!(all->user_exit) && window(all))
			{
				if (closer(all, NULL, 3) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
