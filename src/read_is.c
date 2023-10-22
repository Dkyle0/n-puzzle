/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:26:38 by dkyle             #+#    #+#             */
/*   Updated: 2021/05/23 16:26:44 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	is_re(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '#')
	{
		if (!isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && isdigit(str[i]) && str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '#' && i > 0)
		return (1);
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

void	print_int_i(int imi, int *imap)
{
	int	pr;

	pr = 0;
	while (imi * imi - 1 >= pr)
	{
		printf("%d", imap[pr]);
		printf("  ");
		pr++;
		if (pr % imi == 0)
			printf("\n");
	}
}

int	find(int *imap, int ir)
{
	int	i;
	int	g;
	int	one;

	g = 0;
	while (g < ir)
	{
		i = 0;
		one = 0;
		while (i < ir)
		{
			if (imap[i] == g)
				one++;
			i++;
		}
		if (one != 1)
			return (0);
		g++;
	}
	return (1);
}
