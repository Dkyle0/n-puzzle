/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:41:50 by val               #+#    #+#             */
/*   Updated: 2021/05/22 16:58:48 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	move_next(int *map, t_list *list)
{
	int	tmp;

	if (list->i_b != INVALID_INDEX)
	{
		tmp = map[list->i_zero];
		map[list->i_zero] = map[list->i_b];
		map[list->i_b] = tmp;
	}
}

void	move_prev(int *map, t_list *list)
{
	int	tmp;

	if (list->i_b != INVALID_INDEX)
	{
		tmp = map[list->i_zero];
		map[list->i_zero] = map[list->i_b];
		map[list->i_b] = tmp;
	}
}
