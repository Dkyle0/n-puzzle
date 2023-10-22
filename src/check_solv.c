/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:24:05 by val               #+#    #+#             */
/*   Updated: 2021/05/24 11:26:55 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	odd_solution2(int *inv, int i, int n)
{
	if ((n % 2) == 1 && ((i / n) % 2) == 1)
		*inv += i / n;
	else
		*inv += 1 + i / n;
}

static int	odd_solution(int *map, int n, int len)
{
	int	i;
	int	j;
	int	inv;

	i = 0;
	inv = 0;
	while (i < len)
	{
		if (map[i])
		{
			j = 0;
			while (j < i)
			{
				if (map[j] > map[i])
					inv++;
				j++;
			}
		}
		else
		{
			odd_solution2(&inv, i, n);
		}
		i++;
	}
	return (inv % 2);
}

int	check_solv(int *start, int *target, t_all *all)
{
	if (odd_solution(start, all->all_n, all->len)
		== odd_solution(target, all->all_n, all->len))
		return (1);
	return (0);
}
