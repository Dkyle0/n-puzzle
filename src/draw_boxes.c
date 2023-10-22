/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_boxes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:28:05 by val               #+#    #+#             */
/*   Updated: 2021/05/24 11:01:59 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	set_numbering(SDL_Rect *box, int i, t_all *all)
{
	SDL_Rect	text_field;

	if (SDL_QueryTexture(all->numbering[all->map[i]], NULL, NULL,
			&(text_field.w), &(text_field.h)) < 0)
	{
		dprintf(2, "Failed to get texture information!\nSDL Error: %s\n",
			SDL_GetError());
		return (EXIT_FAILURE);
	}
	text_field.x = box->x + all->side_cube / 2 - text_field.w / 2;
	text_field.y = box->y + all->side_cube / 2 - text_field.h / 2;
	if (draw_texture_from_render(all->numbering[all->map[i]], &text_field, all))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	draw_box(int i, float k, int direction, t_all *all)
{
	SDL_Rect	field;

	field.x = all->xmid + all->side_cube * (i % all->all_n);
	field.y = all->ymid + all->side_cube * (i / all->all_n);
	field.w = all->side_cube;
	field.h = all->side_cube;
	if (direction != NO_MOVEMENT)
	{
		if (k < 0)
			k = 0;
		if (direction == UP_MOVEMENT)
			field.y -= k * all->side_cube;
		else if (direction == RIGHT_MOVEMENT)
			field.x += k * all->side_cube;
		else if (direction == DOWN_MOVEMENT)
			field.y += k * all->side_cube;
		else if (direction == LEFT_MOVEMENT)
			field.x -= k * all->side_cube;
	}
	if (draw_texture_from_render(all->box, &field, all)
		|| set_numbering(&field, i, all))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	draw_boxes2(int *i, int i_zero, t_all *all)
{
	while ((*i) < all->len)
	{
		if ((*i) != i_zero)
		{
			if (draw_box(*i, 0, NO_MOVEMENT, all))
				return (EXIT_FAILURE);
		}
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

int	draw_boxes(time_t t, int i_zero, int i_moved, t_all *all)
{
	int	i;

	i = 0;
	if (i_moved != INVALID_INDEX)
	{
		while (i < all->len)
		{
			if (i != i_zero && i != i_moved)
			{
				if (draw_box(i, 0, NO_MOVEMENT, all))
					return (EXIT_FAILURE);
			}
			i++;
		}
		if (draw_box(i_moved, 1 - (float)(SDL_GetTicks() - t)
			/ (all->screen_delay / MOTION_DELEY),
			get_direction(i_zero - i_moved, all->all_n), all))
			return (EXIT_FAILURE);
	}
	else
	{
		if (draw_boxes2(&i, i_zero, all))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
