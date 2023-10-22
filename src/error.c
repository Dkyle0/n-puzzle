/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:05:49 by val               #+#    #+#             */
/*   Updated: 2021/05/24 10:06:28 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	error_create_surfase(void)
{
	dprintf(2, "Surface could not be created! SDL_Error: %s\n", SDL_GetError());
	return (1);
}
