/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_from_render.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:36:10 by val               #+#    #+#             */
/*   Updated: 2021/05/24 10:49:56 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	draw_texture_from_render(SDL_Texture *texture, SDL_Rect *field, t_all *all)
{
	if (SDL_RenderSetViewport(all->renderer, field) < 0)
	{
		dprintf(2, "Unable to set viewport! SDL_Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (SDL_RenderCopy(all->renderer, texture, NULL, NULL) < 0)
	{
		dprintf(2, "Unable to copy a portion of the texture to the %s %s",
			"current rendering target!\nSDL_Error:\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
