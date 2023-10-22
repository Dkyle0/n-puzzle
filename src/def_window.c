/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 06:49:49 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:08:01 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	get_mouse_down2(int step_x, int x, t_all *all)
{
	if (0 <= x && x < step_x)
		all->type_alg = IDA;
	else if (step_x <= x && x < 2 * step_x)
		all->type_alg = UNIFORM;
	else if (2 * step_x <= x && x < 3 * step_x)
		all->type_alg = A_STAR;
	else if (3 * step_x <= x && x < 4 * step_x)
		all->type_alg = GREEDY_JUMP;
	else if (4 * step_x <= x && x < 5 * step_x)
		all->type_alg = GREEDY;
}

static void	get_mouse_down3(int step_x, int x, t_all *all)
{
	if (0 <= x && x < step_x)
		all->type_heuristic = LINEAR_H;
	else if (step_x <= x && x < 2 * step_x)
		all->type_heuristic = MANH_H;
	else if (2 * step_x <= x && x < 3 * step_x)
		all->type_heuristic = EASY_H;
}

static void	get_mouse_down(t_all *all)
{
	int	x;
	int	y;
	int	step_x;
	int	step_y;

	SDL_GetMouseState(&x, &y);
	step_y = all->sc_heigth / 9;
	if (step_y <= y && y < 2 * step_y)
	{
		step_x = all->sc_width / 3;
		if (0 <= x && x < step_x)
			all->type_puzzle = CLASSIC;
		else if (step_x <= x && x < 2 * step_x)
			all->type_puzzle = SNAIL;
		else if (2 * step_x <= x && x < 3 * step_x)
			all->type_puzzle = SNAKE;
	}
	else if (3 * step_y <= y && y < 4 * step_y)
	{
		get_mouse_down2(all->sc_width / 5, x, all);
	}
	else if (5 * step_y <= y && y < 6 * step_y)
	{
		get_mouse_down3(all->sc_width / 3, x, all);
	}
}

static void	key(SDL_Event *e, int *enter, t_all *all)
{
	if (e->key.keysym.sym == SDLK_EQUALS)
		all->moves_step *= 2;
	else if (e->key.keysym.sym == SDLK_MINUS)
	{
		if (all->moves_step > 1)
			all->moves_step /= 2;
	}
	else if (e->key.keysym.sym == SDLK_w)
		all->screen_delay *= 2;
	else if (e->key.keysym.sym == SDLK_q)
	{
		if (all->screen_delay > 1)
			all->screen_delay /= 2;
	}
	else if (e->key.keysym.sym == SDLK_f)
	{
		if (all->key_f)
			all->key_f = 0;
		else
			all->key_f = 1;
	}
	else if (e->key.keysym.sym == SDLK_RETURN)
		*enter = 1;
}

int	def_window(t_all *all)
{
	int			quit;
	int			enter;
	SDL_Event	e;

	quit = 0;
	enter = 0;
	while (!quit && !enter)
	{
		SDL_SetRenderDrawColor(all->renderer, 0, 0, 0, 255);
		SDL_RenderClear(all->renderer);
		if (draw_question(all->sc_heigth / 9, all))
			return (EXIT_FAILURE);
		SDL_RenderPresent(all->renderer);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN
					&& e.key.keysym.sym == SDLK_ESCAPE))
				quit = 1;
			else if (e.type == SDL_KEYDOWN)
				key(&e, &enter, all);
			else if (e.type == SDL_MOUSEBUTTONDOWN)
				get_mouse_down(all);
		}
	}
	return (all->user_exit = quit);
}
