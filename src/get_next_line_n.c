/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:58:27 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 19:34:30 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

char		g_str[BUFF_SIZE + 1];
char		*g_s;
static char	*g_sline;
int			g_ret;

char	*strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	str[len1 + len2] = '\0';
	while (len2--)
		str[len1 + len2] = s2[len2];
	while (len1--)
		str[len1] = s1[len1];
	return (str);
}

static int	get_line(char *s, char **tmp, char **line)
{
	char		*result;

	result = (char *)malloc(s - *tmp + 1);
	if (!(result))
		return (-1);
	strncpy(result, *tmp, s - *tmp);
	result[s - *tmp] = '\0';
	s = strdup(s + 1);
	if (!(s))
	{
		free(result);
		return (-1);
	}
	free(*tmp);
	*tmp = s;
	*line = result;
	return (1);
}

static int	get_next_line2(ssize_t ret, char **tmp, char **line)
{
	if (*tmp && !(**tmp))
	{
		free(*tmp);
		*tmp = NULL;
		return (ret);
	}
	if (ret == 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	return (ret);
}

int	gnl_w(const int fd, char **line)
{
	g_ret = read(fd, g_str, BUFF_SIZE);
	while (g_ret > 0)
	{
		g_str[g_ret] = '\0';
		g_s = strjoin(g_sline, g_str);
		if (!(g_s))
			return (-1);
		free(g_sline);
		g_sline = g_s;
		g_s = strstr(g_sline, "\n");
		if (g_s)
			return (get_line(g_s, &g_sline, line));
		g_ret = read(fd, g_str, BUFF_SIZE);
	}
	return (get_next_line2(g_ret, &g_sline, line));
}

int	get_next_line_n(const int fd, char **line)
{
	if (fd < 0 || line == NULL || (read(fd, g_str, 0) < 0))
		return (-1);
	if (g_sline)
	{
		g_s = strstr(g_sline, "\n");
		if (g_s)
			return (get_line(g_s, &g_sline, line));
	}
	if (g_sline == NULL)
	{
		(g_sline = (char *)malloc(1));
		g_sline[0] = '\0';
	}
	return (gnl_w(fd, line));
}
