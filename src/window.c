/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:46:11 by val               #+#    #+#             */
/*   Updated: 2021/05/24 18:44:16 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	window2(time_t t, t_all *all)
{
	SDL_SetRenderDrawColor(all->renderer, 0, 0, 0, 255);
	SDL_RenderClear(all->renderer);
	if (draw_decor(all) || draw_boxes(t, all->i_zero, all->i_b,
			all))
		return (EXIT_FAILURE);
	SDL_RenderPresent(all->renderer);
	return (EXIT_SUCCESS);
}

int	window(t_all *all)
{
	int			quit;
	time_t		t;
	int			pause;

	quit = 0;
	t = SDL_GetTicks();
	pause = 0;
	if (all->finish)
		pause = 2;
	if ((all->key_f == 0 && (all->moves_num % all->moves_step) == 0)
		|| all->finish)
	{
		while (!quit && (((SDL_GetTicks() - t) < all->screen_delay) || pause))
		{
			if ((SDL_GetTicks() - t) < (all->screen_delay / MOTION_DELEY + 100))
			{
				if (window2(t, all))
					return (EXIT_FAILURE);
			}
			event_proc(&quit, &pause, &t, all);
		}
	}
	return (all->user_exit = quit);
}
