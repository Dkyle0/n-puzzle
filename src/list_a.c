/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:49:00 by val               #+#    #+#             */
/*   Updated: 2021/05/30 18:35:33 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	move_next_a(int *map, int i_zero, int i_b)
{
	int	tmp;

	tmp = map[i_zero];
	map[i_zero] = map[i_b];
	map[i_b] = tmp;
}

static void	create_list_a2(t_list_a *result, int i_b, t_list_a *prev,
	t_all *all)
{
	if (prev)
	{
		map_copy(prev->map, result->map, all->len);
		result->h = prev->h + 1;
		move_next_a(result->map, result->i_zero, i_b);
		result->i_zero = i_b;
	}
	else
	{
		map_copy(all->map, result->map, all->len);
		result->h = 0;
	}
	result->g = 0;
	result->next = NULL;
	result->prev = prev;
	result->right = NULL;
	result->left = NULL;
}

t_list_a	*create_list_a(int i_zero, int i_b, t_list_a *prev, t_all *all)
{
	t_list_a	*result;

	if (all->free_list_a == NULL)
	{
		result = (t_list_a *)malloc(sizeof(t_list_a));
		if (!(result))
			return (NULL);
		result->map = create_map(all->len);
		if (!(result->map))
		{
			free(result);
			return (NULL);
		}
	}
	else
	{
		result = all->free_list_a;
		all->free_list_a = result->right;
	}
	result->i_zero = i_zero;
	create_list_a2(result, i_b, prev, all);
	return (result);
}

void	free_list_a(t_list_a *head)
{
	free(head->map);
	if (head->left)
		free_list_a(head->left);
	if (head->right)
		free_list_a(head->right);
	free(head);
}
