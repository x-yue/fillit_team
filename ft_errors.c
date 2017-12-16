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
//	if (*board[4] != '\n')
//		return (0);  to be deleted since we have 4 lines (or 3 if you count from 0)
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
//	printf("connections\(if pass the other two tests): %d\n", connect_count);
	if (connect_count != 6 && connect_count != 8)
		return (0);
	return (1);
}

int		ft_errors(char **one_board)
{
	if (four_x_four(one_board) == 0 || input_check(one_board) == 0 ||
		hashtag_test(one_board) == 0)
		return (0);
	return (1);
}
/*
int		main(void)
{
	int i;
	char *str1 = "....\n .##.\n .##.\n ...."; //ok
	char *str2 = "...#\n #...\n ...#\n #...\n \n"; //no ok
	char *str3 = "####\n ....\n ....\n ....\n \n"; //ok
	char *str4 = "....\n ....\n ....\n ####\n \n"; //ok
	char *str5 = "....\n ....\n ..#.\n .###\n \n"; //ok
	char *str6 = "..#.\n ....\n ..##\n ....\n \n"; //no ok
	char *str7 = "..#.\n ..#.\n ..##\n ....\n \n"; // ok
	char *str8 = "....\n ....\n ..##\n .##.\n \n"; //no ok

char	**test1 = ft_strsplit(str1, ' '); // change number here
char	**test2 = ft_strsplit(str2, ' '); // change number here
char	**test3 = ft_strsplit(str3, ' '); // change number here
char	**test4 = ft_strsplit(str4, ' '); // change number here
char	**test5 = ft_strsplit(str5, ' '); // change number here
char	**test6 = ft_strsplit(str6, ' '); // change number here
char	**test7 = ft_strsplit(str7, ' '); // change number here
char	**test8 = ft_strsplit(str8, ' '); // change number here

	i = ft_errors(test1);
	printf("result1: %d\n", i);
	i = ft_errors(test2);
	printf("result2: %d\n", i);
	i = ft_errors(test3);
	printf("result3: %d\n", i);
	i = ft_errors(test4);
	printf("result4: %d\n", i);
	i = ft_errors(test5);
	printf("result5: %d\n", i);
	i = ft_errors(test6);
	printf("result6: %d\n", i);
	i = ft_errors(test7);
	printf("result7: %d\n", i);
	i = ft_errors(test8);
	printf("result8: %d\n", i);
//	int n = 0;
//	while (n < 5)
//	{
//		printf("result test %n: %s\n", n, two_d[n]);
//		n++;
//	}
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
//}*/
