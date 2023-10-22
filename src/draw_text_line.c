/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:15:08 by val               #+#    #+#             */
/*   Updated: 2021/05/24 09:26:59 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	common(SDL_Texture *texture, SDL_Rect line_field, t_all *all)
{
	SDL_Rect	text_field;

	if (SDL_QueryTexture(texture, NULL, NULL, &(text_field.w), &(text_field.h))
		< 0)
	{
		SDL_DestroyTexture(texture);
		dprintf(2, "Failed to get texture information!\nSDL Error: %s\n",
			SDL_GetError());
		return (EXIT_FAILURE);
	}
	text_field.x = line_field.x + line_field.w / 2 - text_field.w / 2;
	text_field.y = line_field.y + line_field.h / 2 - text_field.h / 2;
	if (draw_texture_from_render(texture, &text_field, all))
	{
		SDL_DestroyTexture(texture);
		return (EXIT_FAILURE);
	}
	SDL_DestroyTexture(texture);
	return (EXIT_SUCCESS);
}

int	draw_text_line(char *str, SDL_Rect line_field, SDL_Color color, t_all *all)
{
	SDL_Texture	*texture;

	if (SDL_RenderSetViewport(all->renderer, NULL) < 0)
	{
		dprintf(2, "Unable to set viewport! SDL_Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	SDL_SetRenderDrawColor(all->renderer, all->field_c.r, all->field_c.g,
		all->field_c.b, all->field_c.a);
	SDL_RenderFillRect(all->renderer, &line_field);
	texture = load_from_rendered_text(str, all->field_font, color, all);
	if (texture == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (common(texture, line_field, all));
}

int	draw_text_line_mini(char *str, SDL_Rect line_field, SDL_Color color,
	t_all *all)
{
	SDL_Texture	*texture;

	if (SDL_RenderSetViewport(all->renderer, NULL) < 0)
	{
		dprintf(2, "Unable to set viewport! SDL_Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	SDL_SetRenderDrawColor(all->renderer, all->field_c2.r, all->field_c2.g,
		all->field_c2.b, all->field_c2.a);
	SDL_RenderFillRect(all->renderer, &line_field);
	texture = load_from_rendered_text(str, all->field_fmini, color, all);
	if (texture == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (common(texture, line_field, all));
}
