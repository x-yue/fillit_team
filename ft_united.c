/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_united.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:34:42 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/17 06:20:18 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char	**malloc_it(void)
{
	char	**tmp;
	int		line;

	line = 0;
	if (!(tmp = (char**)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (line < 4)
	{
		if (!(tmp[line] = (char*)malloc(sizeof(char) * 6)))
			return (NULL);
		tmp[line][5] = '\0';
		line++;
	}
	tmp[line] = NULL;
	return (tmp);
}

int		small_nb(int *k)
{
	int		small_nb;
	int		n;

	n = 0;
	small_nb = k[n];
	while (k[n] && n < 4)
	{
		if (small_nb > k[n])
			small_nb = k[n];
		n++;
	}
	return (small_nb);
}

int		first_left(char **board)
{
	nb_list	united;
	int		k[4];
	int		n;

	united.mv_left = 0;
	n = 0;
	united.line = 0;
	while (united.line < 4)
	{
		united.i = 0;
		while (united.i <= 3 && n < 4)
		{
			if (board[united.line][united.i] == '#')
			{
//				printf("when there is %c, the location i is : %d \n", board[united.line][united.i], united.i);
				k[n] = united.i;
				printf("i is: %d k[n] is :%d\n", united.i, k[n]);
//				printf("the n is : %d\n the k[n] is: %d\n the i is %d\n", n, k[n], united.i);
				n++;
			}
			united.i++;
		}
		united.line++;
	}
	united.mv_left = small_nb(k);
	printf("the small nb is :%d\n", small_nb(k));
	return (united.mv_left);
}/*
void	ft_up(char **board, int line, int i, int mv_up)
{
	char	tmp[4][5];
	int		tmp_line;

	tmp_line = 0;
	if (line > 0 && mv_up > 0)
	{
		tmp[tmp_line][i] = board[line][i];
		board[line][i] = board[line - mv_up][i];
		board[line - mv_up][i] = tmp[tmp_line][i];
	}
}
*/
char	**ft_left(char **board)
{
	nb_list	united;
	char	**tmp;
	int		tmp_i;

	tmp = malloc_it();
	tmp_i = 0;
	united.line = 0;
	united.mv_left = first_left(board);
	while (united.line < 4)
	{
		united.i = 0;
		while (united.i <= 3)
		{
			if (board[united.line][united.i] == '#')
			{
//			printf("test1");
//			printf("i each time: %d || mv_left = %d\n", united.i, united.mv_left);
				if (united.i > 0 && united.mv_left > 0)
				{			
					tmp[united.line][tmp_i] = board[united.line][united.i];
					board[united.line][united.i] = board[united.line][united.i - united.mv_left];
					board[united.line][united.i - united.mv_left] = tmp[united.line][tmp_i];
				}
			}
			united.i++;
		}
		united.line++;
	}
	return (board);
}

char	**ft_united(char **board)
{
	nb_list		united;
	int			tmp_line;
	char		**tmp;

	tmp = malloc_it();
	tmp_line = 0;
	united.line = 0;
	united.hashtag_count = 0;
	while (united.line < 4)
	{
		united.i = 0;
		while (united.i <= 3)
		{
			if (board[united.line][united.i] == '#')
			{
				united.hashtag_count++;
				if (united.hashtag_count == 1)
					united.mv_up = united.line;
			// remove	ft_up(board, united.line, united.i, united.mv_up);
				if (united.line > 0 && united.mv_up > 0)
				{
//					printf("before: %s\n", board[united.line]);
					tmp[tmp_line][united.i] = board[united.line][united.i];
					board[united.line][united.i] = board[united.line - united.mv_up][united.i];
					board[united.line - united.mv_up][united.i] = tmp[tmp_line][united.i];
//					printf("after: %s\n", board[united.line]);
				}
	//	remove		ft_left(board, united.line, united.i, united.mv_left);
			}
			united.i++;
		}
		united.line++;
	}
//	int n = 0;
//	while (board[n])
//	{
//		printf("before ft_left:\n%s\n", board[n]);
//		n++;
//	}
	board = ft_left(board);
	return (board);
}

int		main(void)
{
/*	int k[4];
	k[0] = 5;
	k[1] = 8;
	k[2] = 3;
	k[3] = 5;
	small_nb(k);
	printf("%d\n", small_nb(k));

*/
	int n;
	char *str1 = "....\n ..#.\n .##.\n .#..\n";
	char **test1 = ft_strsplit(str1, ' ');
	n = 0;
	while (n < 4)
	{
		printf("original: %s\n", test1[n]);
		n++;
	}
	n = 0;
	char **restult = ft_united(test1);
	while (n < 4)
	{
		printf("result: %s\n", restult[n]);
		n++;
	}
	
	return 0;
}
