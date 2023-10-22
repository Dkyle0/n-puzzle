/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 03:48:43 by val               #+#    #+#             */
/*   Updated: 2021/05/23 11:26:36 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	find_min_weight(int *move_weight)
{
	int	i;
	int	i_min;

	i = 0;
	i_min = INVALID_INDEX;
	while (i < 4)
	{
		if (move_weight[i] != INVALID_INDEX)
		{
			if (i_min == INVALID_INDEX || move_weight[i] < move_weight[i_min])
			{
				i_min = i;
			}
		}
		i++;
	}
	return (i_min);
}
