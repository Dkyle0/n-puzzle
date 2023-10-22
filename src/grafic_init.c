/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:41:42 by val               #+#    #+#             */
/*   Updated: 2021/05/24 11:01:23 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	init_var_color(t_all *all)
{
	all->text_color.r = 255;
	all->text_color.g = 255;
	all->text_color.b = 255;
	all->text_color.a = 255;
	all->field_tc.r = 217;
	all->field_tc.g = 246;
	all->field_tc.b = 255;
	all->field_tc.a = 255;
	all->field_tc2.r = 149;
	all->field_tc2.g = 164;
	all->field_tc2.b = 172;
	all->field_tc2.a = 255;
	all->field_c2.r = 33;
	all->field_c2.g = 91;
	all->field_c2.b = 122;
	all->field_c2.a = 255;
	all->field_c.r = 106;
	all->field_c.g = 177;
	all->field_c.b = 199;
	all->field_c.a = 255;
}

void	init_var(t_all *all)
{
	all->window = NULL;
	all->renderer = NULL;
	all->screen_surface = NULL;
	all->box = NULL;
	all->font_box = NULL;
	all->field_font = NULL;
	all->field_fmini = NULL;
	all->numbering = NULL;
	init_var_color(all);
	all->succ_init = 0;
	all->user_exit = 0;
	all->finish = 0;
	all->pr_time = 0;
	all->moves_step = 1;
	all->screen_delay = DELAY_STATES;
	if (all->screen_delay < 1)
		all->screen_delay = 1;
	all->key_f = 0;
	all->type_puzzle = CLASSIC;
	all->type_alg = IDA;
	all->type_heuristic = LINEAR_H;
}

static int	grafic_init2(t_all *all)
{
	all->font_box = TTF_OpenFont(FONT_BOX3, all->side_cube / 2);
	if (all->font_box == NULL)
	{
		dprintf(2, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return (EXIT_FAILURE);
	}
	all->field_font = TTF_OpenFont(FONT_BOX2, all->side_cube / 3);
	if (all->field_font == NULL)
	{
		TTF_CloseFont(all->font_box);
		dprintf(2, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return (EXIT_FAILURE);
	}
	all->field_fmini = TTF_OpenFont(FONT_BOX2, all->side_cube / 6);
	if (all->field_font == NULL)
	{
		TTF_CloseFont(all->font_box);
		TTF_CloseFont(all->field_font);
		dprintf(2, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return (EXIT_FAILURE);
	}
	all->succ_init = 7;
	if (fill_numbering(all))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	grafic_init1(t_all *all)
{
	SDL_GetWindowSize(all->window, &(all->sc_width), &(all->sc_heigth));
	if (all->sc_width < SC_W_MIN || all->sc_heigth < SC_H_MIN)
	{
		dprintf(2, "The window is too small to use!\nScreen width %d %s %d %s",
			all->sc_width, "pix;\nScreen heigth", all->sc_heigth, "pix.\n");
		return (EXIT_FAILURE);
	}
	all->screen_surface = SDL_GetWindowSurface(all->window);
	if (all->screen_surface == NULL)
		return (error_create_surfase());
	all->succ_init = 4;
	initial_size_data(all);
	all->box = load_texture(BOX_FILE, all);
	if (all->box == NULL)
		return (error_create_surfase());
	all->succ_init = 5;
	if (TTF_Init() < 0)
	{
		dprintf(2, "SDL_ttf could not initialize! SDL_ttf Error: %s\n",
			TTF_GetError());
		return (EXIT_FAILURE);
	}
	all->succ_init = 6;
	return (grafic_init2(all));
}

int	grafic_init(t_all *all)
{
	init_var(all);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		dprintf(2, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	all->succ_init = 1;
	all->window = SDL_CreateWindow("N-puzzle", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SC_W_MIN, SC_H_MIN, SDL_WINDOW_SHOWN);
	if (all->window == NULL)
	{
		dprintf(2, "Window could not be created! SDL_Error: %s\n",
			SDL_GetError());
		return (EXIT_FAILURE);
	}
	all->succ_init = 2;
	all->renderer = SDL_CreateRenderer(all->window, -1, SDL_RENDERER_SOFTWARE);
	if (all->renderer == NULL)
	{
		dprintf(2, "Renderer could not be created! SDL Error: %s\n",
			SDL_GetError());
		return (EXIT_FAILURE);
	}
	all->succ_init = 3;
	return (grafic_init1(all));
}
