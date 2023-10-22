/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 04:07:28 by val               #+#    #+#             */
/*   Updated: 2021/05/25 20:25:01 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	forb_ind(t_list *list, int present_index)
{
	if (present_index == UP_MOVEMENT)
	{
		list->i_move[DOWN_MOVEMENT] = INVALID_INDEX;
	}
	else if (present_index == LEFT_MOVEMENT)
	{
		list->i_move[RIGHT_MOVEMENT] = INVALID_INDEX;
	}
	else if (present_index == DOWN_MOVEMENT)
	{
		list->i_move[UP_MOVEMENT] = INVALID_INDEX;
	}
	else if (present_index == RIGHT_MOVEMENT)
	{
		list->i_move[LEFT_MOVEMENT] = INVALID_INDEX;
	}
}

static int	vertex_jump0(t_list **list, t_list *present_move, t_all *all)
{
	(*list) = create_next_list(present_move, all);
	if (!(*list))
		return (EXIT_FAILURE);
	find_possible_moves(all->i_zero, (*list)->i_move, all);
	if (present_move)
		forb_ind((*list), present_move->ii_min_weight);
	return (EXIT_SUCCESS);
}

static int	vertex_jump2(t_list *list, int deep, int *min, t_all *all)
{
	list->i_b = list->i_move[list->ii_min_weight];
	move_next(all->map, list);
	all->i_zero = list->i_b;
	(all->compl_time)++;
	list->move_weight[list->ii_min_weight]
		= summ_h(all, all->type_heuristic);
	if (deep != 0)
	{
		if (vertex_jump(list, all, deep - 1, min))
		{
			if (!(all->head))
				free(list);
			return (EXIT_FAILURE);
		}
		if ((*min) < list->move_weight[list->ii_min_weight])
			list->move_weight[list->ii_min_weight] = (*min);
		del_list(list->next, all);
		list->next = NULL;
	}
	move_prev(all->map, list);
	return (EXIT_SUCCESS);
}

static int	vertex_jump3(t_list *list, int deep,
	t_all *all)
{
	list->ii_min_weight = find_min_weight(list->move_weight);
	if (list->ii_min_weight == INVALID_INDEX)
	{
		printf("Can't find the least weight in map!\n");
		if (!(all->head))
			free(list);
		return (EXIT_FAILURE);
	}
	if (deep == DEEP_LEN || all->type_alg == GREEDY)
	{
		list->i_b = list->i_move[list->ii_min_weight];
		move_next(all->map, list);
		(all->moves_num)++;
		all->present_move = list;
		all->i_zero = list->i_b;
	}
	return (EXIT_SUCCESS);
}

int	vertex_jump(t_list *present_move, t_all *all, int deep, int *min_w)
{
	int		i;
	int		min;
	t_list	*list;

	if (vertex_jump0(&list, present_move, all))
		return (EXIT_FAILURE);
	i = 0;
	while (i < 4)
	{
		if (list->i_move[i] != INVALID_INDEX)
		{
			list->ii_min_weight = i;
			if (vertex_jump2(list, deep, &(min), all))
				return (EXIT_FAILURE);
		}
		else
			list->move_weight[i] = INVALID_INDEX;
		i++;
	}
	if (vertex_jump3(list, deep, all))
		return (EXIT_FAILURE);
	if (min_w)
		*min_w = list->move_weight[list->ii_min_weight];
	return (EXIT_SUCCESS);
}
