/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:38:54 by val               #+#    #+#             */
/*   Updated: 2021/05/24 09:40:36 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	grafic_close2(t_all *all)
{
	if (all->succ_init > 2)
	{
		if (all->succ_init > 3)
		{
			if (all->succ_init > 4)
			{
				if (all->succ_init > 5)
				{
					if (all->succ_init > 6)
					{
						TTF_CloseFont(all->font_box);
						TTF_CloseFont(all->field_font);
						TTF_CloseFont(all->field_fmini);
					}
					TTF_Quit();
				}
				SDL_DestroyTexture(all->box);
			}
			SDL_FreeSurface(all->screen_surface);
		}
		SDL_DestroyRenderer(all->renderer);
	}
}

void	grafic_close(t_all *all)
{
	int	i;

	if (all->numbering)
	{
		i = 0;
		while (i <= all->len)
		{
			SDL_DestroyTexture(all->numbering[i]);
			i++;
		}
		free(all->numbering);
	}
	if (all->succ_init > 0)
	{
		if (all->succ_init > 1)
		{
			grafic_close2(all);
			SDL_DestroyWindow(all->window);
		}
		SDL_Quit();
	}
}
