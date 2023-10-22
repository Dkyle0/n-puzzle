/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:09:40 by ghusk             #+#    #+#             */
/*   Updated: 2021/05/30 19:20:01 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

t_list_a	*find_list_a(t_list_a *head, t_list_a *list, t_all *all)
{
	t_list_a	*result;

	if (head && head->right)
	{
		result = find_list_a(head->right, list, all);
		if (result)
			return (result);
	}
	while (head)
	{
		if (head->i_zero == list->i_zero && head->g == list->g
			&& compare_map(head->map, list->map, all->len))
			return (head);
		head = head->left;
	}
	return (NULL);
}

static t_list_a	*extract_list_a2(t_list_a *head, t_list_a *list)
{
	while (head)
	{
		if (head->left == list)
		{
			head->left = list->left;
			list->left = NULL;
			return (list);
		}
		head = head->left;
	}
	return (NULL);
}

t_list_a	*extract_list_a(t_list_a *head, t_list_a *list, t_all *all)
{
	if (head && head->right)
	{
		if (head->right == list)
		{
			if (list->left)
			{
				head->right = list->left;
				list->left = NULL;
				head->right->right = list->right;
			}
			else
				head->right = list->right;
			list->right = NULL;
			return (list);
		}
		if (find_list_a(head->right, list, all))
			return (list);
	}
	return (extract_list_a2(head, list));
}

t_list_a	*extract_top_a(t_all *all)
{
	t_list_a	*list;

	list = all->open_list;
	if (list->left)
	{
		all->open_list = list->left;
		list->left = NULL;
		all->open_list->right = list->right;
	}
	else
		all->open_list = list->right;
	list->right = NULL;
	return (list);
}
