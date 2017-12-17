/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:27:03 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/17 06:39:14 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**swap_up(char **board, int line, int i, int mv_up)
{
	char	**tmp;
	int		tmp_line;

	tmp_line = 0;
	tmp = malloc_it();
	if (line > 0 && mv_up > 0)
	{
		tmp[tmp_line][i] = board[line][i];
		board[line][i] = board[line - mv_up][i];
		board[line - mv_up][i] = tmp[line][i];
	}
	return (board);
}
