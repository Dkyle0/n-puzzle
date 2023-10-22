/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:31:40 by val               #+#    #+#             */
/*   Updated: 2021/05/24 19:13:15 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	*create_def_map(int n, int len, int mode)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * len);
	if (!(result))
		return (NULL);
	if (mode == SNAIL)
	{
		snail(0, n, 1, result);
	}
	else if (mode == CLASSIC)
	{
		classic(n, result);
	}
	else if (mode == SNAKE)
	{
		snake(n, result);
	}
	return (result);
}

int	find_zero_index(int *map, int len)
{
	int	i;

	i = 0;
	{
		while (i < len)
		{
			if (map[i] == 0)
				return (i);
			i++;
		}
	}
	return (INVALID_INDEX);
}

void	find_possible_moves(int	i_zero, int *dst, t_all *all)
{
	int	i;

	i = i_zero - all->max_int[0];
	if (i >= 0)
		dst[UP_MOVEMENT] = i;
	else
		dst[UP_MOVEMENT] = NO_MOVEMENT;
	if ((i_zero % all->max_int[0] + 1) < all->max_int[0])
		dst[RIGHT_MOVEMENT] = i_zero + 1;
	else
		dst[RIGHT_MOVEMENT] = NO_MOVEMENT;
	i = i_zero + all->max_int[0];
	if (i < all->len)
		dst[DOWN_MOVEMENT] = i;
	else
		dst[DOWN_MOVEMENT] = NO_MOVEMENT;
	if ((i_zero % all->max_int[0] - 1) >= 0)
		dst[LEFT_MOVEMENT] = i_zero - 1;
	else
		dst[LEFT_MOVEMENT] = NO_MOVEMENT;
}

int	get_direction(int i_dif, int n)
{
	if (i_dif == -n)
	{
		return (UP_MOVEMENT);
	}
	else if (i_dif == 1)
	{
		return (RIGHT_MOVEMENT);
	}
	else if (i_dif == n)
	{
		return (DOWN_MOVEMENT);
	}
	else if (i_dif == -1)
	{
		return (LEFT_MOVEMENT);
	}
	return (NO_MOVEMENT);
}
