/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:10:51 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/13 23:31:00 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		appear_line(char **board)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (line < 4)
	{
		while (i < 4)
		{
			if (board[line][i] == '#')
				return (line);
			i++;
		}
		line++;
	}
	return (0);
}


int		appear_colomn(char **board)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (line < 4)
	{
		while (i < 4)
		{
			if (board[line][i] == '#')
				return(i);
			i++;
		}
		line++;
	}
	return (0);
}

int		appearance(char **board)
{
	int		i;
	int		line;
	int		four;

	four = 4;
	i = appear_colomn(board);
	line = appear_line(board);
	while (four > 1)
	{
		//if (i <= 2)
		// this is to be done, i m thinking how to just record all the #s :) 

		if (i == 3)
		{
			if (board[line + 1][i] != '#')
				return (0);
		}
	}
}
int		hashtag_loc(char **board)
{
	int i;
	int line;

	line = 0;
	while (line < 4)
	{
		i = 0;
		while (i <= 3)
		{
			if (board[line][i] == '#')
			{
				if (board[line + 1][i] != '#' && board[line - 1][i] != '#' && 
				board[line][i + 1] != '#' && board[line][i - 1] != '#')
					return (0);
			}
			i++;
		}
		line++;
	}
	return (1);
}
