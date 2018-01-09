/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:44 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/17 04:00:04 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
int		four_x_four(char **board)
{
	int i;
	int line;

	line = 0;
	while (line < 4)
	{
		i = 0;
		while (board[line][i] != '\n')
			i++;
		if (i != 4)
			return (0);
		line++;
	}
	return (1);
}
*/

int		input_check(char **board)
{
	int i;
	int line;
	int nb_hashtag;

	line = 0;
	nb_hashtag = 0;
	while (line < 4)
	{
		i = 0;
		while (i <= 3)
		{
			if (board[line][i] != '#' && board[line][i] != '.')
				return (0);
			if (board[line][i] == '#')
				nb_hashtag++;
			i++;
		}
		if (board[line][4] != '\n')
			return (0);
		line++;
	}
	if (nb_hashtag != 4)
		return (0);
	return (1);
}

int		c_count(char **board, int line, int i)
{
	int connect_count;

	connect_count = 0;
	if (line <= 3 && board[line + 1][i] == '#')
		connect_count++;
	if (line >= 1 && board[line - 1][i] == '#')
		connect_count++;
	if (i <= 2 && board[line][i + 1] == '#')
		connect_count++;
	if (i >= 1 && board[line][i - 1] == '#')
		connect_count++;
	return (connect_count);
}

int		hashtag_test(char **board)
{
	int i;
	int line;
	int connect_count;

	line = 0;
	connect_count = 0;
	while (line < 4)
	{
		i = 0;
		while (i <= 3)
		{
			if (board[line][i] == '#')
				connect_count += c_count(board, line, i);
			i++;
		}
		line++;
	}
	if (connect_count != 6 && connect_count != 8)
		return (0);
	return (1);
}

int		ft_errors(char **one_board)
{
	if (input_check(one_board) == 0 || hashtag_test(one_board) == 0) // check return value if we use four x four
		return (0);
	return (1);
}
