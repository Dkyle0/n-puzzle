/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:03:22 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:27:08 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	add_el_to_queue3(t_list_a *new, t_list_a *list, t_list_a *old)
{
	if (new->h > list->h)
	{
		old->right = new;
		new->right = list->right;
		new->left = list;
		list->right = NULL;
	}
	else
	{
		while (list && new->h < list->h)
		{
			old = list;
			list = list->left;
		}
		if (!list)
		{
			list = old;
			list->left = new;
		}
		else
		{
			new->left = list->left;
			list->left = new;
		}
	}
}

void	add_el_to_queue2(t_list_a *new, t_list_a *list, t_list_a *old)
{
	while (list && new->f > list->f)
	{
		old = list;
		list = list->right;
	}
	if (!list)
	{
		list = old;
		list->right = new;
	}
	else if (list->f != new->f)
	{
		new->right = list->right;
		list->right = new;
	}
	else
		add_el_to_queue3(new, list, old);
}

void	add_el_to_queue(t_list_a *new, t_all *all)
{
	t_list_a	*list;
	t_list_a	*old;

	list = all->open_list;
	old = NULL;
	if (new->f < list->f || (new->f == list->f && new->h > list->h))
	{
		new->right = list;
		all->open_list = new;
	}
	else
		add_el_to_queue2(new, list, old);
}

void	vertex_a_end(t_list_a *open_list, t_all *all)
{
	t_list_a	*list;

	if (all->open_list != open_list)
		list = extract_list_a(all->open_list, open_list, all);
	else
		list = extract_top_a(all);
	list->right = all->close_list;
	all->close_list = list;
}
