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

void	create_random(int *nbr, t_all *all)
{
	int		i;
	int		j;
	int		k;
	time_t	t;

	i = 0;
	srand((unsigned)time(&t));
	while (i < all->all_n * all->all_n)
	{
		nbr[i] = i;
		i++;
	}
	i = 0;
	k = 0;
	while (i < all->all_n * all->all_n)
	{
		j = rand() % (all->all_n * all->all_n);
		while (nbr[j] < 0 && k < all->all_n * all->all_n)
			j = rand() % (all->all_n * all->all_n);
		all->i_all[i] = j;
		nbr[j] = -1;
		k++;
		i++;
	}
	print_int_i(all->all_n, all->i_all);
}

void	em_for_gen(t_all *all, int *nbr)
{
	if (!(all->max_int))
		cloxer(all);
	if (!(all->i_all))
		cloxer(all);
	if (!(nbr))
	{
		printf("Error malloc for map in generator failed\n");
		exit(0);
	}	
}

void	m_generator(t_all *all, const char *option)
{
	int	*nbr;
	int	size;
	int	i;

	size = 3;
	if (option[2])
		if (atoi(&option[2]) > 3 && atoi(&option[2]) < 6)
			size = atoi(&option[2]);
	all->max_str = -1;
	nbr = (int *)malloc(size * size * sizeof(int));
	all->all_n = size;
	all->i_all = (int *)malloc(sizeof(int) * (all->all_n * all->all_n));
	all->max_int = (int *)malloc(sizeof(int) * size);
	em_for_gen(all, nbr);
	i = 0;
	while (i < size)
	{
		all->max_int[i] = size;
		i++;
	}
	create_random(nbr, all);
	free(nbr);
}
