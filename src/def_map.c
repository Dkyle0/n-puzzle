/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:01 by val               #+#    #+#             */
/*   Updated: 2021/05/25 21:03:19 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	snail2(int i0, int n, int *k, int *map)
{
	int	i;
	int	i_lim;
	int	j;

	i_lim = n - i0;
	j = --i_lim;
	i = --i_lim;
	while (i >= i0)
	{
		map[j * n + i] = (*k)++;
		i--;
	}
	j = i_lim;
	i = n * n;
	while (j > i0 && (*k) != i)
	{
		map[j * n + i0] = (*k)++;
		j--;
	}
	if ((*k) == i && j > i0)
		map[j * n + i0] = 0;
	i0++;
	if (i0 < n - i0)
		snail(i0, n, *k, map);
}

void	snail(int i0, int n, int k, int *map)
{
	int	i;
	int	i_lim;
	int	j;

	i = i0;
	i_lim = n - i0;
	if (k == n * n)
	{
		map[i0 * n + i] = 0;
		return ;
	}
	while (i < i_lim)
	{
		map[i0 * n + i] = k++;
		i++;
	}
	i = i_lim - 1;
	j = i0 + 1;
	while (j < i_lim)
	{
		map[j * n + i] = k++;
		j++;
	}
	snail2(i0, n, &k, map);
}

void	classic(int n, int *map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < n)
	{
		i = 0;
		while (i < n)
		{
			map[j * n + i] = ++k;
			i++;
		}
		j++;
	}
	map[n * n - 1] = 0;
}

static void	snake2(int j, int n, int *map, int *k)
{
	int	i;

	i = 0;
	while (i < n)
	{
		map[j * n + i] = ++(*k);
		i++;
	}
}

void	snake(int n, int *map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < n)
	{
		if (j % 2)
		{
			i = n;
			while (i--)
				map[j * n + i] = ++k;
		}
		else
			snake2(j, n, map, &k);
		j++;
	}
	if (n % 2)
		map[n * n - 1] = 0;
	else
		map[n * (n - 1)] = 0;
}
