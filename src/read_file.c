/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/23 16:26:44 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	transfer(int *imap, int imi, char **re, int line)
{
	int	i;

	i = 0;
	while (i < imi)
	{
		if (is_re(re[i]) == 0)
			break ;
		imap[i + line * imi] = atoi(re[i]);
		i++;
	}
}

void	kill_space_free(char **map, int *imap, int lc, int *max)
{
	printf("error 2 lines with size\n");
	if (map)
		free_m(map, lc - 1);
	if (imap)
		free(imap);
	if (max)
		free(max);
	exit(0);
}

int	kill_space(char **map, int *imap, int lc, int *max)
{
	int		i;
	int		ir;
	int		imi;
	int		ss;
	char	**re;

	init_ks(&i, &ir, &ss);
	while (ir < lc && i < lc)
	{
		if (is_str_size(map[i]))
			ss++;
		if (ss > 1)
			kill_space_free(map, imap, lc, max);
		imi = word_n(map[i], ' ');
		if (imi > 2)
		{
			if (!is_digit_str(map[i]))
				simbol_in_str(map, i, imi);
			re = strsplit(map[i], ' ');
			transfer(imap, imi, re, ir);
			ks_if_end(max, &ir, imi, re);
		}
		i++;
	}
	return (ret_ks(imap, ir));
}

int	move2(t_all *all, int lc)
{
	all->max_int = (int *)malloc(sizeof(int) * lc);
	if (!(all->max_int))
		cloxer(all);
	all->i_all = (int *)malloc(sizeof(int) * (lc * lc));
	if (!(all->i_all))
		cloxer(all);
	all->all_n = kill_space(all->s_all, all->i_all, lc, all->max_int);
	if (check_line(all->max_int, all->all_n) < 0
		|| check_unic(all, all->all_n) < 0)
	{
		printf("error\n");
		exit(0);
	}
	return (0);
}

int	read_file(char const *argv[], t_all *all)
{
	int		fd;
	char	*line;
	int		lc;
	int		sn;

	if (argv[1][0] == '-' && argv[1][1] =='g')
		m_generator(all, argv[1]);
	else
	{
		init_read(all, argv, &lc);
		fd = open(argv[1], O_RDONLY);
		sn = get_next_line_n(fd, &line);
		while (sn == 1)
		{
			all->s_all[all->max_str] = line;
			if (!(all->s_all[all->max_str]))
				free_p1x(all->s_all, all->max_str);
			all->max_str += 1;
			sn = get_next_line_n(fd, &line);
		}
		close(fd);
		move2(all, lc);
	}
	return (0);
}
