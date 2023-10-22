/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by val               #+#    #+#             */
/*   Updated: 2021/05/30 16:37:25 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	a_star_algorithm3(t_all *all)
{
	(all->compl_size)++;
	all->start_time = SDL_GetTicks();
	if (vertex_a(all->open_list, all))
		return (closer(all, "Failed to create list!\nN-puzzle", 4 | 1));
	all->end_time = SDL_GetTicks();
	all->pr_time += (all->end_time - all->start_time);
	all->i_zero = all->open_list->i_zero;
	map_copy(all->open_list->map, all->map, all->len);
	all->moves_num = all->open_list->h;
	if (!(all->user_exit) && window(all))
	{
		if (closer(all, NULL, 3) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	a_star_algorithm2(t_list_a *list, t_all *all)
{
	if (all->type_alg != UNIFORM)
	{
		list->g = summ_h(all, all->type_heuristic);
		list->f = list->g + list->h;
	}
	else
	{
		all->present_move_a = list;
	}
	all->open_list = list;
	if (all->type_alg == IDA)
	{
		all->h_min = list->h;
		all->h_max = list->h;
		all->h_count = 0;
		all->skip = 0;
	}
	all->end_time = SDL_GetTicks();
	all->pr_time += (all->end_time - all->start_time);
}

int	a_star_algorithm(t_all *all)
{
	t_list_a	*list;

	if (!(compare_map(all->map, all->def_map, all->len)))
	{
		all->start_time = SDL_GetTicks();
		list = create_list_a(all->i_zero, INVALID_INDEX, NULL, all);
		if (!(list))
			return (closer(all, "Failed to create list!\nN-puzzle", 5));
		a_star_algorithm2(list, all);
		if (!(all->user_exit) && window(all))
		{
			if (closer(all, NULL, 3) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		while (!(compare_map(all->open_list->map, all->def_map, all->len)))
		{
			if (a_star_algorithm3(all))
				return (EXIT_FAILURE);
		}
		all->present_move_a = all->open_list;
		map_copy(all->open_list->map, all->map, all->len);
		connect_way(all);
	}
	return (EXIT_SUCCESS);
}
