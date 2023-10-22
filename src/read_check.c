/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_generator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/23 16:26:44 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	check_nbr_line(int *imap, int ir)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while (i < ir)
	{
		if (imap[i] > m)
			m = imap[i];
		i++;
	}
	if (m != ir - 1)
	{
		printf("ivalid map: so big number %d\n", m);
		free(imap);
		exit(0);
	}
	if (!find(imap, ir))
	{
		printf("ivalid map: non-consecutive numbers \n");
		free(imap);
		exit(0);
	}
}

int	check_line(int *max, int lc)
{
	int	i;
	int	b;

	i = 0;
	if (lc < 3)
		return (-1);
	while (i < lc)
	{
		b = max[0];
		if (max[i] != b || lc != b)
			return (-1);
		i++;
	}
	return (1);
}

int	cu2(t_all *all, int i_c1, int one_0)
{
	if ((all->i_all[i_c1] == 0 && all->i_all[i_c1 + 1] != 0)
		|| (all->i_all[i_c1] != 0 && all->i_all[i_c1 + 1] == 0 ))
		one_0 = 1;
	if (one_0 == 0)
		return (-1);
	return (0);
}

int	check_unic(t_all *all, int lc)
{
	int	i_c1;
	int	i_c2;
	int	nbr;
	int	one_0;

	one_0 = 0;
	i_c1 = 0;
	i_c2 = 1;
	while (i_c1 < lc * lc - 2)
	{
		nbr = all->i_all[i_c1];
		if (nbr == 0)
			one_0 = 1;
		while (i_c2 < lc * lc - 1)
		{
			if (nbr == all->i_all[i_c2])
				return (-1);
			i_c2++;
		}
		i_c1++;
		i_c2 = i_c1 + 1;
	}
	return (cu2(all, i_c1, one_0));
}
