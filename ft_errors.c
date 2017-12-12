/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:44 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/12 23:48:28 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// four_x_four fonction checks if the form is in 4x4 forma or not
// input_check checks if there is any other signs in the form, i put (i < 3) because the board[line][4] is supposed to be '\n'.
//if it's not '.' or '#' in the form, it will return an error.

int		four_x_four(char **board)
{
	int i;
	int line;

	i = 0;
	line = 1;
	while (line < 5)
	{
		// probably have to put i = 0 here
		while (board[line][i])
		{
			i++;
		}
		line++;
	}
	if (*board[5] != '\n' || i != 4)
		return (0);
	// the 5th line is supposed to be '\n' for all forms (include the last one in the test)
	return (1);
}

int		input_check(char **board)
{
	int i;
	int line;
	int nb_hashtag;

	i = 0;
	line = 1;
	nb_hashtag = 0;
	while (line < 4) // <= 4 since line initialized to 1?
	{
		while (i < 3)
		{
			if (board[line][i] != '#' && board[line][i] != '.')
				return (0);
			if (i == '#')
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

int		ft_errors(char ***board)
{
	int table_nb;
//	int line_all;
//	int line_form;

	table_nb = 0;
//	line_all = 0;
	while (board[table_nb])
	{
//	{	while (board[line_form])
//		{
//			line_form = 0;
//			while (line_form < 5)
//			{
//				
//			}
//			line_all += line_form;
//		}
//		table_nb++;
//	}
		if (four_x_four(board[table_nb]) == 0 ||
				input_check(board[table_nb]) == 0)
			return (0);
		table_nb++;
	}
	return (1);
}
// donc i will need to create ***table first in the main

