/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-puzzle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:55:51 by val               #+#    #+#             */
/*   Updated: 2021/05/29 16:43:06 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	all_init(t_all *all)
{
	if (!(all))
	{
		perror("N-puzzle");
		return (EXIT_FAILURE);
	}
	all->max_str = 1;
	all->map = NULL;
	all->tmp_map = NULL;
	all->head = NULL;
	all->present_move = NULL;
	all->free_list = NULL;
	all->def_map = NULL;
	all->i_b = INVALID_INDEX;
	all->moves_num = 0;
	all->compl_size = 0;
	all->compl_time = 0;
	all->present_move_a = NULL;
	all->free_list_a = NULL;
	all->open_list = NULL;
	all->close_list = NULL;
	return (EXIT_SUCCESS);
}

static int	main_finish(t_all *all)
{
	all->finish = 1;
	print_solve(all);
	printf("Congratulations, the puzzle is solved!\n");
	printf("Complexity time: %lu\n", all->compl_time);
	printf("Complexity size: %lu\n", all->compl_size);
	printf("Time: %u ms\n", all->pr_time);
	printf("Moved: %lu\n", all->moves_num);
	if (!(all->user_exit) && window(all))
	{
		if (closer(all, NULL, 3) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (!(all->user_exit))
	{
		grafic_close(all);
	}
	np_close(all);
	return (EXIT_SUCCESS);
}

static int	main2(t_all *all)
{
	all->i_zero = find_zero_index(all->i_all, all->len);
	if (all->i_zero == INVALID_INDEX)
		return (closer(all, "Wrong map! No empty cell found\n", 0));
	all->map = create_map(all->len);
	if (!(all->map))
		return (closer(all, "Failed to create map!\nN-puzzle", 4));
	all->tmp_map = create_map(all->len);
	if (!(all->tmp_map))
		return (closer(all, "Failed to create map!\nN-puzzle", 4));
	if (grafic_init(all))
		return (closer(all, NULL, 1));
	map_copy(all->i_all, all->map, all->len);
	if (def_window(all))
	{
		if (closer(all, NULL, 3) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	all->def_map = create_def_map(all->max_int[0], all->len, all->type_puzzle);
	if (!(all->def_map))
		return (closer(all, "Failed to create default map!\nN-puzzle", 1 | 4));
	if (!(check_solv(all->map, all->def_map, all)))
		return (closer(all,
				"Wrong map! There is no solution for this type of puzzle!\n",
				1));
	return (EXIT_SUCCESS);
}

static int	processing(t_all *all)
{
	if (all->type_alg == IDA || all->type_alg == A_STAR
		|| all->type_alg == UNIFORM)
	{
		if (a_star_algorithm(all))
			return (EXIT_FAILURE);
	}
	else if (all->type_alg == GREEDY_JUMP || all->type_alg == GREEDY)
	{
		if (greedy_hopping_algorithm(all))
			return (EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (all_init(all))
		return (EXIT_FAILURE);
	if (argc == 2)
		read_file(argv, all);
	else
		read_input(all);
	all->len = all->all_n * all->all_n;
	if (main2(all))
	{
		return (EXIT_FAILURE);
	}
	if (!(all->user_exit) && window(all))
	{
		if (closer(all, NULL, 3) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (processing(all))
	{
		return (EXIT_FAILURE);
	}
	return (main_finish(all));
}
