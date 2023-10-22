/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 00:28:07 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:21:26 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	list_in_open_list(t_list_a *list, t_all *all)
{
	t_list_a	*dst;

	dst = find_list_a(all->open_list, list, all);
	if (dst)
	{
		if (list->h < dst->h)
		{
			dst->prev = list->prev;
			dst->h = list->h;
			dst->f = dst->g + dst->h;
			if (dst != all->open_list)
			{
				dst = extract_list_a(all->open_list, dst, all);
				add_el_to_queue(dst, all);
			}
		}
		return (1);
	}
	return (0);
}
