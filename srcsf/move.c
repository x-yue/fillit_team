/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:34:42 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/27 01:16:36 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** malloc_it will create a temporary board, it will be used in ft_swap_up
** to put all the # to the top place
*/

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

/*
** to put all the # to the top place : mv_up == distance to the top
*/

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

/*
**first_left is used to calculate the shortest distance to the left of all #
** it will return a mv_l for ft_left to move lefter :)
*/

int		first_left(char **board)
{
	t_move	uni;

	uni.n = 0;
	uni.l = 0;
	while (uni.l < 4)
	{
		uni.i = 0;
		while (uni.i <= 3 && uni.n < 4)
		{
			if (board[uni.l][uni.i] == '#')
			{
				uni.k[uni.n] = uni.i;
				uni.n++;
			}
			uni.i++;
		}
		uni.l++;
	}
	uni.mv_l = uni.k[0];
	while (uni.k[uni.n--] && uni.n > 0)
	{
		if (uni.mv_l > uni.k[uni.n])
			uni.mv_l = uni.k[uni.n];
	}
	return (uni.mv_l);
}

/*
**ft_left will move the tetri to the left by deleting the distance of mv_l
**callslculated from first_left
*/

char	**ft_left(char **board)
{
	t_move	uni;
	char	tmp;

	uni.l = 0;
	uni.mv_l = first_left(board);
	while (uni.l < 4)
	{
		uni.i = 0;
		while (uni.i <= 3)
		{
			if (board[uni.l][uni.i] == '#')
			{
				if (uni.i > 0 && uni.mv_l > 0)
				{
					tmp = board[uni.l][uni.i];
					board[uni.l][uni.i] = board[uni.l][uni.i - uni.mv_l];
					board[uni.l][uni.i - uni.mv_l] = tmp;
				}
			}
			uni.i++;
		}
		uni.l++;
	}
	return (board);
}

/*
** ft_united is the fonction calls all the other fonction to move tetris
** to the upper-left corner
*/

char	**ft_united(char **board)
{
	t_move	uni;

	uni.l = 0;
	uni.hashtag_count = 0;
	while (uni.l < 4)
	{
		uni.i = 0;
		while (uni.i <= 3)
		{
			if (board[uni.l][uni.i] == '#')
			{
				uni.hashtag_count++;
				if (uni.hashtag_count == 1)
					uni.mv_up = uni.l;
				ft_swap_up(board, uni.l, uni.i, uni.mv_up);
			}
			uni.i++;
		}
		uni.l++;
	}
	board = ft_left(board);
	return (board);
}
