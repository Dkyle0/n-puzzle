/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_decor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:49:55 by val               #+#    #+#             */
/*   Updated: 2021/05/24 10:25:40 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static char	*get_str_tail_line(t_all *all)
{
	char	*result;
	char	*str;

	result = (char *)malloc(sizeof(char) * 85);
	if (!result)
	{
		return (NULL);
	}
	strcpy(result, "Moves:");
	str = result + 6;
	SDL_ultoa(all->moves_num, str, 10);
	str = str + strlen(str);
	strcpy(str, "    Time:");
	str = str + 9;
	if (all->head == NULL && all->open_list == NULL)
	{
		SDL_ultoa(0, str, 10);
	}
	else
	{
		SDL_ultoa((all->pr_time / 1000) + 1, str, 10);
	}
	return (result);
}

int	draw_decor(t_all *all)
{
	SDL_Rect	line_field;
	char		*str;
	int			result;

	line_field.x = 0;
	line_field.y = 0;
	line_field.w = all->sc_width;
	line_field.h = all->side_cube - 1;
	if (all->head == NULL)
		str = "START";
	else if (all->finish)
		str = "FINISH";
	else
		str = "MAP";
	if (draw_text_line(str, line_field, all->field_tc, all))
		return (EXIT_FAILURE);
	line_field.y = all->sc_heigth - all->side_cube + 1;
	str = get_str_tail_line(all);
	if (!(str))
		return (EXIT_FAILURE);
	result = draw_text_line(str, line_field, all->field_tc, all);
	free(str);
	return (result);
}
