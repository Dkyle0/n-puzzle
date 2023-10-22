/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/23 16:26:44 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	reallmal(t_all *all)
{
	char	**text;
	int		i;

	i = 0;
	text = (char **) malloc(sizeof (char *) * all->max_str);
	while (i < all->max_str - 1)
	{
		text[i] = all->s_all[i];
		i++;
	}
	free(all->s_all);
	all->max_str *= 2;
	all->s_all = malloc_map(all->max_str);
	i = 0;
	while (i < all->max_str / 2 - 1)
	{
		all->s_all[i] = text[i];
		i++;
	}
	free(text);
}

void	frexit(t_all *all, char *msg)
{
	perror(msg);
	free(all->s_all);
	exit(0);
}

void	read_p(t_all *all)
{
	int			ret;
	char		*line;

	all->s_all = malloc_map(all->max_str);
	ret = get_next_line_n(0, &line);
	while (ret > 0)
	{
		if (all->all_n + 1 == all->max_str)
			reallmal(all);
		all->s_all[all->all_n] = line;
		all->all_n++;
		ret = get_next_line_n(0, &line);
	}
	if (ret == -1 || all->all_n == 0)
		frexit(all, "error read line\n");
	ret = 0;
	while (line[ret])
		ret++;
	if (ret < all->all_n)
		frexit(all, "error last line\n");
}

void	read_input(t_all *all)
{
	all->all_n = 0;
	read_p(all);
	move2(all, all->all_n);
	printf("input ok\n");
}
