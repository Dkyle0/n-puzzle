/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:11:34 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 16:58:08 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	length_arr(char const *s, char c)
{
	size_t		lem_arr;
	size_t		len_str;

	lem_arr = 0;
	len_str = 0;
	while (s[lem_arr + len_str])
	{
		if (s[lem_arr + len_str] != c)
		{
			lem_arr++;
			while (s[lem_arr + len_str] && s[lem_arr + len_str] != c)
				len_str++;
		}
		else
			len_str++;
	}
	return (lem_arr);
}

static size_t	length_str(char const *s, char c)
{
	size_t		len_str;

	len_str = 0;
	while (s[len_str] && s[len_str] != c)
		len_str++;
	return (len_str);
}

static char	**fill_arr(char ***p_arr, size_t len_arr, char const *s, char c)
{
	size_t	len_str;
	size_t	i;
	char	**arr;

	arr = *p_arr;
	i = 0 - 1;
	while (++i < len_arr)
	{
		len_str = length_str(s, c);
		arr[i] = (char *)malloc((len_str + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			while (i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		arr[i][len_str] = '\0';
		while (len_str--)
			arr[i][len_str] = s[len_str];
		s = s + length_str(s, c);
		while (*s && *s == c)
			s++;
	}
	return (arr);
}

char	**strsplit(char const *s, char c)
{
	size_t	lem_arr;
	char	**arr;

	if (s == NULL)
		return (NULL);
	lem_arr = 0;
	while (*s && *s == c)
		s++;
	lem_arr = length_arr(s, c);
	arr = (char **)malloc((lem_arr + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[lem_arr] = NULL;
	if (fill_arr(&arr, lem_arr, s, c) == NULL)
		return (NULL);
	return (arr);
}
