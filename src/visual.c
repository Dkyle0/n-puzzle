/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:41:30 by val               #+#    #+#             */
/*   Updated: 2021/05/24 10:50:08 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	initial_size_data(t_all *all)
{
	if (all->sc_width < all->sc_heigth)
	{
		all->side_cube = all->sc_width / (all->all_n + 2);
	}
	else
	{
		all->side_cube = all->sc_heigth / (all->all_n + 2);
	}
	all->xmid = (all->sc_width - all->all_n * all->side_cube) / 2;
	all->ymid = (all->sc_heigth - all->all_n * all->side_cube) / 2;
}

SDL_Texture	*load_texture(char *name_file, t_all *all)
{
	SDL_Texture	*result;
	SDL_Surface	*loaded_surface;

	result = NULL;
	loaded_surface = IMG_Load(name_file);
	if (loaded_surface == NULL)
	{
		dprintf(2, "Unable to load image %s! SDL Error: %s\n", name_file,
			IMG_GetError());
	}
	else
	{
		result = SDL_CreateTextureFromSurface(all->renderer, loaded_surface);
		if (result == NULL)
		{
			dprintf(2, "Unable to create texture from %s! SDL Error: %s\n",
				name_file, SDL_GetError());
		}
		SDL_FreeSurface(loaded_surface);
	}
	return (result);
}

SDL_Texture	*load_from_rendered_text(char *str, TTF_Font *font, SDL_Color color,
	t_all *all)
{
	SDL_Texture	*result;
	SDL_Surface	*text_surface;

	result = NULL;
	text_surface = TTF_RenderText_Solid(font, str, color);
	if (text_surface == NULL )
	{
		dprintf(2, "Unable to render text surface! SDL_ttf Error: %s\n",
			TTF_GetError());
	}
	else
	{
		result = SDL_CreateTextureFromSurface(all->renderer, text_surface);
		if (result == NULL)
		{
			dprintf(2, "Unable to create texture from rendered text!\n%s %s",
				"SDL Error:\n", SDL_GetError());
		}
		SDL_FreeSurface(text_surface);
	}
	return (result);
}

static int	free_numbering_proc(int	i, t_all *all)
{
	while (--i >= 0)
	{
		SDL_DestroyTexture(all->numbering[i]);
	}
	free(all->numbering);
	all->numbering = NULL;
	return (EXIT_FAILURE);
}

int	fill_numbering(t_all *all)
{
	int			i;
	char		str[3];

	all->numbering = (SDL_Texture **)malloc((all->len + 1)
			* sizeof(SDL_Texture *));
	if (!(all->numbering))
	{
		perror("Failed to create numbering list!\nN-puzzle");
		return (EXIT_FAILURE);
	}
	str[0] = '\0';
	str[1] = '\0';
	str[2] = '\0';
	i = 0;
	while (i <= all->len)
	{
		SDL_itoa(i, str, 10);
		all->numbering[i] = load_from_rendered_text(str, all->font_box,
				all->text_color, all);
		if (all->numbering[i] == NULL)
			return (free_numbering_proc(i, all));
		i++;
	}
	return (EXIT_SUCCESS);
}
