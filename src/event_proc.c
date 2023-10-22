/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 06:44:46 by val               #+#    #+#             */
/*   Updated: 2021/05/25 21:13:59 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	list_a_move(SDL_Event *e, time_t *t, t_all *all)
{
	if (e->key.keysym.sym == SDLK_RIGHT)
	{
		if (all->present_move_a->next)
		{
			all->i_zero = all->present_move_a->next->i_zero;
			all->i_b = all->present_move_a->i_zero;
			move_next_a(all->map, all->i_zero, all->i_b);
			all->present_move_a = all->present_move_a->next;
			all->moves_num = all->present_move_a->h;
			*t = SDL_GetTicks();
		}
	}
	else if (e->key.keysym.sym == SDLK_LEFT)
	{
		if (all->present_move_a->prev)
		{
			all->i_zero = all->present_move_a->prev->i_zero;
			all->i_b = all->present_move_a->i_zero;
			move_next_a(all->map, all->i_zero, all->i_b);
			all->present_move_a = all->present_move_a->prev;
			all->moves_num = all->present_move_a->h;
			*t = SDL_GetTicks();
		}
	}
}

static void	list_move2(time_t *t, t_all *all)
{
	move_prev(all->map, all->present_move);
	all->i_b = all->present_move->i_b;
	all->i_zero = all->present_move->i_zero;
	all->moves_num = move_len(all->present_move->prev);
	all->present_move = all->present_move->prev;
	all->moves_num = move_len(all->present_move);
	*t = SDL_GetTicks();
}

static void	list_move(SDL_Event *e, time_t *t, t_all *all)
{
	if (e->key.keysym.sym == SDLK_RIGHT)
	{
		if (!(all->present_move))
		{
			all->present_move = all->head;
			move_next(all->map, all->present_move);
			all->i_b = all->present_move->i_zero;
			all->i_zero = all->present_move->i_b;
			all->moves_num = move_len(all->present_move);
			*t = SDL_GetTicks();
		}
		else if ((all->present_move->next))
		{
			all->present_move = all->present_move->next;
			move_next(all->map, all->present_move);
			all->i_b = all->present_move->i_zero;
			all->i_zero = all->present_move->i_b;
			all->moves_num = move_len(all->present_move);
			*t = SDL_GetTicks();
		}
	}
	else if (e->key.keysym.sym == SDLK_LEFT && all->present_move)
		list_move2(t, all);
}

static void	key(SDL_Event *e, int *pause, t_all *all)
{
	if (e->key.keysym.sym == SDLK_SPACE)
	{
		if (*pause)
			*pause = 0;
		else
			*pause = 1;
	}
	else if (e->key.keysym.sym == SDLK_EQUALS)
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
		all->key_f++;
}

void	event_proc(int *quit, int *pause, time_t *t, t_all *all)
{
	SDL_Event	e;	

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN
				&& e.key.keysym.sym == SDLK_ESCAPE))
			*quit = 1;
		else if (e.type == SDL_KEYDOWN)
		{
			key(&e, pause, all);
			if (all->finish)
			{
				if ((all->type_alg == IDA || all->type_alg == A_STAR
						|| all->type_alg == UNIFORM) && all->present_move_a)
					list_a_move(&e, t, all);
				if ((all->type_alg == GREEDY_JUMP || all->type_alg == GREEDY)
					&& all->head)
					list_move(&e, t, all);
			}
		}
	}
}
