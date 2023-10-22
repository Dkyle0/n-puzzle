/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_question2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:32:58 by val               #+#    #+#             */
/*   Updated: 2021/05/24 10:26:01 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	draw_question3(SDL_Rect line_field, int step_x, t_all *all)
{
	char		str[22];

	SDL_uitoa(all->screen_delay, str, 10);
	if (draw_text_line_mini(str, line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (all->key_f)
	{
		if (draw_text_line_mini("True", line_field, all->field_tc, all))
			return (EXIT_FAILURE);
	}
	else
	{
		if (draw_text_line_mini("False", line_field, all->field_tc, all))
			return (EXIT_FAILURE);
	}
	line_field.x += step_x;
	SDL_uitoa(all->moves_step, str, 10);
	return (draw_text_line_mini(str, line_field, all->field_tc, all));
}

int	draw_question2(SDL_Rect line_field, int step_x, int step_y, t_all *all)
{
	line_field.y += step_y;
	line_field.x = 0;
	line_field.w = all->sc_width;
	if (draw_text_line("Other parameters", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.y += step_y;
	line_field.w = step_x;
	if (draw_text_line_mini("Delay, ms", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (draw_text_line_mini("Skipping the process", line_field, all->field_tc,
			all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (draw_text_line_mini("Movements step", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.y += step_y;
	line_field.x = 0;
	return (draw_question3(line_field, step_x, all));
}
