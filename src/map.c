/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:12:02 by val               #+#    #+#             */
/*   Updated: 2021/05/23 03:07:41 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	compare_map(int *map0, int *map1, int len)
{
	while (len-- > 0)
	{
		if (map0[len] != map1[len])
		{
			return (0);
		}
	}
	return (1);
}

int	*create_map(int len)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * len);
	if (!(result))
		return (NULL);
	return (result);
}

void	map_copy(int *src, int *dst, int len)
{
	while (len--)
	{
		dst[len] = src[len];
	}
}
