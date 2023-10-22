/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:03:22 by val               #+#    #+#             */
/*   Updated: 2021/05/23 19:42:42 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	manh_dist(int *now, int *target, t_all *all, int i)
{
	int	value;
	int	j;
	int	dist;

	dist = 0;
	j = 0;
	value = now[i];
	while (target[j] != value && j < all->all_n * all->all_n)
		j++;
	dist += abs((j % all->all_n) - (i % all->all_n));
	dist += abs((j / all->all_n) - (i / all->all_n));
	return (dist);
}

int	manh_fh(int *now, int *target, t_all *all)
{
	int	s;
	int	i;

	s = 0;
	i = 0;
	while (i < all->all_n * all->all_n - 1)
	{
		s += manh_dist(now, target, all, i);
		i++;
	}
	return (s);
}

int	linear_conflict(int *now, int *target, t_all *all)
{
	int	s;
	int	i;

	s = 0;
	i = 0;
	while (i < all->all_n * all->all_n)
	{
		while ((now[i] == target[i] && i < all->all_n * all->all_n)
			|| now[i] == 0)
			i++;
		all->n = now[i];
		all->row = i + 1;
		if (is_target_in_line(target, all) && is_conflict(target, now, all))
			s += 2;
		i++;
	}
	return (s);
}

int	easy_fh(int *now, int *target, t_all *all)
{
	int	s;
	int	i;

	s = all->all_n * all->all_n;
	i = 0;
	while (i < all->all_n * all->all_n)
	{
		if (now[i] == target[i])
			s--;
		i++;
	}
	if (s < 0)
		return (0);
	return (s);
}

int	summ_h(t_all *all, char flag)
{
	if (flag == 'e')
		return (easy_fh(all->map, all->def_map, all));
	if (flag == 'm')
		return (manh_fh(all->map, all->def_map, all));
	if (flag == 'l')
		return (manh_fh(all->map, all->def_map, all)
			+ linear_conflict(all->map, all->def_map, all));
	return (manh_fh(all->map, all->def_map, all)
		+ linear_conflict(all->map, all->def_map, all));
}
