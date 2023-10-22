/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/24 19:07:39 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	simbol_in_str(char **map, int i, int imi)
{
	printf("not digit simbol in str %s\n", map[i]);
	free_p1x(map, imi);
}

void	init_read(t_all *all, char const *argv[], int *lc)
{
	all->max_str = 0;
	*lc = line_count(argv);
	all->s_all = malloc_map(*lc);
}

void	init_ks(int *i, int *ir, int *ss)
{
	*i = 0;
	*ir = 0;
	*ss = 0;
}

int	ret_ks(int *imap, int ir)
{
	check_nbr_line(imap, ir * ir);
	print_int_i(ir, imap);
	return (ir);
}

void	ks_if_end(int *max, int *ir, int imi, char **re)
{
	max[*ir] = imi;
	free_m(re, imi);
	*ir += 1;
}
