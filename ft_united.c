/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_united.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:34:42 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/19 22:37:56 by yuxu             ###   ########.fr       */
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
	return (tmp);
}

char	**ft_swap_up(char **board, int line, int i, int mv_up)
{
	char	**tmp;

	tmp = malloc_it();
	if (line > 0 && mv_up > 0)
	{
		tmp[line][i] = board[line][i];
		board[line][i] = board[line - mv_up][i];
		board[line - mv_up][i] = tmp[line][i];
	}
	return (board);
}

int		first_left(char **board)
{
	nb_list	uni;

	uni.n = 0;
	uni.line = 0;
	while (uni.line < 4)
	{
		uni.i = 0;
		while (uni.i <= 3 && uni.n < 4)
		{
			if (board[uni.line][uni.i] == '#')
			{
				uni.k[uni.n] = uni.i;
				uni.n++;
			}
			uni.i++;
		}
		uni.line++;
	}
	uni.mv_l = uni.k[0];
	while (uni.k[uni.n--] && uni.n > 0)
	{
		if (uni.mv_l > uni.k[uni.n])
			uni.mv_l = uni.k[uni.n];
	}
	return (uni.mv_l);
}

char	**ft_left(char **board)
{
	nb_list	uni;

	uni.tmp = malloc_it();
	uni.line = 0;
	uni.mv_l = first_left(board);
	while (uni.line < 4)
	{
		uni.i = 0;
		while (uni.i <= 3)
		{
			if (board[uni.line][uni.i] == '#')
			{
				if (uni.i > 0 && uni.mv_l > 0)
				{
					uni.tmp[uni.line][uni.i] = board[uni.line][uni.i];
					board[uni.line][uni.i] = board[uni.line][uni.i - uni.mv_l];
					board[uni.line][uni.i - uni.mv_l] = uni.tmp[uni.line][
						uni.i];
				}
			}
			uni.i++;
		}
		uni.line++;
	}
	return (board);
}

char	**ft_united(char **board)
{
	nb_list		uni;

	uni.tmp = malloc_it();
	uni.line = 0;
	uni.hashtag_count = 0;
	while (uni.line < 4)
	{
		uni.i = 0;
		while (uni.i <= 3)
		{
			if (board[uni.line][uni.i] == '#')
			{
				uni.hashtag_count++;
				if (uni.hashtag_count == 1)
					uni.mv_up = uni.line;
				ft_swap_up(board, uni.line, uni.i, uni.mv_up);
			}
			uni.i++;
		}
		uni.line++;
	}
	board = ft_left(board);
	return (board);
}
/*
int		main(void)
{
	int n;
	char *str1 = "....\n ....\n ....\n .#..\n";
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
}*/
