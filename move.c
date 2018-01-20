/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:34:42 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/20 06:09:40 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	char	tmp;

	if (line > 0 && mv_up > 0)
	{
		tmp = board[line][i];
		board[line][i] = board[line - mv_up][i];
		board[line - mv_up][i] = tmp;
	}
	return (board);
}

int		first_left(char **board)
{
	t_move	uni;

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
	t_move	uni;

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
					board[uni.line][uni.i - uni.mv_l] = uni.tmp[uni.line]
						[uni.i];
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
	t_move	uni;

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
