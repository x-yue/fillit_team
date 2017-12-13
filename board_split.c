/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:48:53 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/13 22:37:33 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**line_split(char *test)
{
	char	**one_board;
	int		line;
	int		content;
	int		i;

	line = 0;
	i = 0;
	content = 0;
	while (content < 21)
	{
		while (line < 5)
		{
			while (i < 5)
			{
				one_board[line][i] = test[content];
				i++;
				content++;
			}
			line++;
		}
	}
	return (one_board);
}

char	***board_split(char *test)
{
	char	***boards;
	char	**one_board;
	int		board_nb;
	int		line_all;
	int		line_board;
	int		count;
	int		i;

	board_nb = 0;
	line_all = 0;
	while (board_nb < (ft_strlen(test) * 5 / 21))
	{
		while (
		one_board = line_split(test);
		***board[board_nb] = one_board;
		board_nb++;
//not done yet - but probably not useful
