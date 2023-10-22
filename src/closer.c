/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:45:21 by val               #+#    #+#             */
/*   Updated: 2021/05/30 17:21:47 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	closer(t_all *all, char *msg, int option)
{
	if (msg)
	{
		if (option & 4)
			perror(msg);
		else
			dprintf(2, "%s", msg);
	}
	if (option == 3)
	{
		if (all->user_exit)
		{
			grafic_close(all);
			return (EXIT_SUCCESS);
		}
	}
	if ((option & 1) && !(all->user_exit))
	{
		grafic_close(all);
	}
	np_close(all);
	return (EXIT_FAILURE);
}

void	cloxer(t_all *all)
{
	np_close(all);
	exit(0);
}

void	np_close(t_all *all)
{
	if (all->map)
		free(all->map);
	if (all->def_map)
		free(all->def_map);
	if (all->tmp_map)
		free(all->tmp_map);
	if (all->head)
		free_list(all->head);
	if (all->free_list)
		free_list(all->free_list);
	if (all->max_int)
		free(all->max_int);
	if (all->i_all)
		free(all->i_all);
	if (all->s_all && all->max_str > 1)
		free_m(all->s_all, all->max_str - 1);
	if (all->free_list_a)
		free_list_a(all->free_list_a);
	if (all->open_list)
		free_list_a(all->open_list);
	if (all->close_list)
		free_list_a(all->close_list);
	free(all);
}

void	free_p1x(char **res, int i)
{
	free_m(res, i);
	exit (0);
}
