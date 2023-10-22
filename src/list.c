/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:49:00 by val               #+#    #+#             */
/*   Updated: 2021/05/22 16:57:33 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

t_list	*create_list(int i_zero, t_list *prev, t_all *all)
{
	t_list	*result;

	result = all->free_list;
	if (result)
	{
		all->free_list = result->next;
	}
	else
	{
		result = (t_list *)malloc(sizeof(t_list));
		if (!(result))
			return (NULL);
	}
	result->i_zero = i_zero;
	result->ii_min_weight = INVALID_INDEX;
	result->next = NULL;
	result->prev = prev;
	return (result);
}

t_list	*create_next_list(t_list *list, t_all *all)
{
	if (list)
	{
		list->next = create_list(list->i_b, list, all);
		return (list->next);
	}
	return (create_list(all->i_zero, NULL, all));
}

void	free_list(t_list *head)
{
	t_list	*list;

	while (head)
	{
		list = head->next;
		free(head);
		if (list)
		{
			head = list->next;
			free(list);
		}
		else
			head = NULL;
	}
}
