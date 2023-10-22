/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_question.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:04:21 by val               #+#    #+#             */
/*   Updated: 2021/05/24 11:07:03 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	draw_puzzle(SDL_Rect line_field, int step_x, t_all *all)
{
	if (all->type_puzzle == CLASSIC)
	{
		if (draw_text_line_mini("Classic", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Classic", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (all->type_puzzle == SNAIL)
	{
		if (draw_text_line_mini("Snail", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Snail", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (all->type_puzzle == SNAKE)
	{
		if (draw_text_line_mini("Snake", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Snake", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	draw_alg2(SDL_Rect line_f, int step_x, t_all *all)
{
	line_f.x += step_x;
	if (all->type_alg == A_STAR)
	{
		if (draw_text_line_mini("A*", line_f, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("A*", line_f, all->field_tc, all))
		return (EXIT_FAILURE);
	line_f.x += step_x;
	if (all->type_alg == GREEDY_JUMP)
	{
		if (draw_text_line_mini("Greedy-jump", line_f, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Greedy-jump", line_f, all->field_tc, all))
		return (EXIT_FAILURE);
	line_f.x += step_x;
	if (all->type_alg == GREEDY)
	{
		if (draw_text_line_mini("Greedy", line_f, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Greedy", line_f, all->field_tc, all))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	draw_alg(SDL_Rect *line_field, int step_x, int step_y, t_all *all)
{
	line_field->y += step_y;
	line_field->x = 0;
	line_field->w = all->sc_width;
	if (draw_text_line("Algorithm", *line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	step_x = all->sc_width / 5;
	line_field->y += step_y;
	line_field->w = step_x;
	if (all->type_alg == IDA)
	{
		if (draw_text_line_mini("IDA*", *line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("IDA*", *line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field->x += step_x;
	if (all->type_alg == UNIFORM)
	{
		if (draw_text_line_mini("Uniform", *line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Uniform", *line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	return (draw_alg2(*line_field, step_x, all));
}

static int	draw_heuristic(SDL_Rect line_field, int step_x, t_all *all)
{
	if (all->type_heuristic == LINEAR_H)
	{
		if (draw_text_line_mini("Linear", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Linear", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (all->type_heuristic == MANH_H)
	{
		if (draw_text_line_mini("Manhattan", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Manhattan", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.x += step_x;
	if (all->type_heuristic == EASY_H)
	{
		if (draw_text_line_mini("Easy", line_field, all->field_tc2, all))
			return (EXIT_FAILURE);
	}
	else if (draw_text_line_mini("Easy", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	draw_question(int step_y, t_all *all)
{
	int			step_x;
	SDL_Rect	line_field;

	line_field.x = 0;
	line_field.y = 0;
	line_field.h = step_y;
	line_field.w = all->sc_width;
	if (draw_text_line("Puzzle type", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	step_x = all->sc_width / 3;
	line_field.y += step_y;
	line_field.w = step_x;
	if (draw_puzzle(line_field, step_x, all)
		|| draw_alg(&line_field, step_x, step_y, all))
		return (EXIT_FAILURE);
	line_field.y += step_y;
	line_field.x = 0;
	line_field.w = all->sc_width;
	if (draw_text_line("Heuristic function", line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	step_x = all->sc_width / 3;
	line_field.y += step_y;
	line_field.w = step_x;
	return (draw_heuristic(line_field, step_x, all)
		|| draw_question2(line_field, step_x, step_y, all));
}
