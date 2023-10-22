/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:03:22 by val               #+#    #+#             */
/*   Updated: 2021/05/23 19:42:42 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	is_conflict(int *target, int *now, t_all *all)
{
	int	i;
	int	max;

	max = all->row - 1;
	while ((all->row - 1) % all->all_n != 0 && max < all->all_n * all->all_n)
		max++;
	i = all->row;
	while (i < max)
	{
		if (now[i] == 0 && i + 1 < max)
			i++;
		all->n = now[i];
		all->row = i + 1;
		if (is_target_in_line(target, all) && now[i] > all->n)
			return (1);
		i++;
	}
	i = max;
	while (i < all->all_n * all->all_n)
	{
		if (all->n > now[i] && (i + 1) % all->row == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_target_in_line(int *target, t_all *all)
{
	int	i;
	int	max;

	max = all->row - 1;
	while ((all->row - 1) % all->all_n != 0 && max < all->all_n * all->all_n)
		max++;
	i = max - all->all_n;
	if (i < 0)
		i = 0;
	while (i < max)
	{
		if (target[i])
			if (all->n == target[i])
				return (1);
		i++;
	}
	i = 0;
	while (i < all->all_n * all->all_n)
	{
		if (all->n == target[i] && (i + 1) % all->row == 0)
			return (1);
		i++;
	}
	return (0);
}
