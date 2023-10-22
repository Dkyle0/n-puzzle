/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/24 19:00:10 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	word_n(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (!(s) || !(s[0]))
		return (0);
	while (s[i + 1])
	{
		if (s[i] == '#')
			return (n - 1);
		if (((s[i] != c) && s[i + 1] == c)
			|| ((s[i] != c) && s[i + 1] == '\0'))
			n++;
		i++;
		if (s[i] == c && !s[i + 1])
			n--;
	}
	return (n);
}

void	free_m(char **res, int a)
{
	while (0 <= a)
	{
		free(res[a]);
		a--;
	}
	free(res);
	res = NULL;
}

int	line_count(char const *argv[])
{
	int		i;
	int		fd;
	int		r;
	char	buff[1];

	i = 0;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	r = read(fd, buff, 1);
	while (r > 0)
	{
		if (buff[0] == '\n')
			i++;
		r = read(fd, buff, 1);
	}
	if ((r < 0) || (i == 0) || (buff[0] != '\n'))
	{
		printf("error\n");
		exit(0);
	}
	close(fd);
	return (i);
}

char	**malloc_map(int all_line)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (all_line));
	if (!(map))
	{
		printf("error allocated map\n");
		exit(0);
	}
	return (map);
}
