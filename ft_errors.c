/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:44 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/13 23:31:05 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// four_x_four fonction checks if the form is in 4x4 forma or not
// input_check checks if there is any other signs in the form, i put (i < 3) because the board[line][4] is supposed to be '\n'.
//if it's not '.' or '#' in the form, it will return an error.

#include "libft.h"
#include <stdio.h>

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
	if (*board[4] != '\n')
		return (0);
	return (1);
}

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

// for two dimention tables:
int		ft_errors(char **one_board)
{
	if (four_x_four(one_board) == 0 || input_check(one_board) == 0)
		return (0);
	return (1);
}

int		main(void)
{
	char *str;
	char **two_d;
	int i;
	int n = 0;
	str = "...#\n .#..\n ....\n ##..\n \n";
	two_d = ft_strsplit(str, ' ');
	i= ft_errors(two_d);
	printf("%d\n", i);
	while (n < 5)
	{
		printf("%s\n", two_d[n]);
		n++;
	}
	printf("%s\n", str);
	return (0);
}

//for three dimention boardS:
//int		ft_errors(char ***board)
//{
//	int table_nb;
//
///	table_nb = 0;
//	while (board[table_nb])
//	{
//		if (four_x_four(board[table_nb]) == 0 ||
//				input_check(board[table_nb]) == 0)
//			return (0);
//		table_nb++;
//	}
//	return (1);
//}
