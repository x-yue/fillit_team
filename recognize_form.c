/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:10:51 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/10 21:27:31 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//the appear line fonction gives how many lines # appeared in each form

int		appear_line(char **board)
{
	int i;
	int line;
	int count_appear_lines;

	i = 0;
	line = 1;
	count_appear_lines = 0;
	while (line < 4)
	{
		while (i < 4)
		{
			if (board[line][i] == '#')
				count_appear_lines++;
			i++;
		}
		line++;
	}
	return (count_appear_lines);
}


