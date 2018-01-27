/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:34:42 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/27 00:26:56 by ablin            ###   ########.fr       */
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
	char	**tmp;

	tmp = malloc_it();
	if (line > 0 && mv_up > 0)
	{
		tmp[line][i] = board[line][i];
		board[line][i] = board[line - mv_up][i];
		board[line - mv_up][i] = tmp[line][i];
	}
	free(tmp);
	tmp = NULL;
	return (board);
}

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
** Freed tmp here, it might be helpful
** to consult with Andrea later
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
