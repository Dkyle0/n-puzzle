/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:47:18 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:21:57 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	print_solve2(t_all *all)
{
	int			count;
	t_list_a	*list_a;

	list_a = all->present_move_a;
	while (list_a->prev)
	{
		list_a = list_a->prev;
	}
	list_a = list_a->next;
	while (list_a)
	{
		count = 3 * (all->all_n);
		while (count-- > 0)
		{
			write(1, "-", 1);
		}
		write(1, "\n", 1);
		print_int_i(all->all_n, list_a->map);
		list_a = list_a->next;
	}
}

void	print_solve(t_all *all)
{
	t_list	*list;
	int		count;

	if (all->type_alg == GREEDY || all->type_alg == GREEDY_JUMP)
	{
		map_copy(all->i_all, all->map, all->len);
		list = all->head;
		while (list)
		{
			move_next(all->map, list);
			count = 3 * (all->all_n);
			while (count-- > 0)
			{
				write(1, "-", 1);
			}
			write(1, "\n", 1);
			print_int_i(all->all_n, all->map);
			list = list->next;
		}
	}
	else if ((all->type_alg == IDA || all->type_alg == A_STAR
			|| all->type_alg == UNIFORM) && all->open_list)
	{
		print_solve2(all);
	}
}
