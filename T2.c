#include "fillit.h"
#include "libft.h"
#include <stdio.h>

pos_struct	ft_position(char **board)
{
	pos_struct	pos;

	pos.line = 0;
	while (board[pos.line] != NULL)
	{
		pos.col = 0;
		while (board[pos.line][pos.col] != '\0' && board[pos.line][pos.col] != '#')
			pos.col++;
		pos.line++;
	}
	pos.line--; //check si la fonction a atteint la fin du board
	return (pos);
}

int			pos_check(char **map, int line, int col)
{
	pos_struct	pos;

	pos.o_line = 0;
	pos.o_col = 0;
	ft_position(board, pos);
}

char	**ft_place(char **map)
{
	pos_struct	pos;//maybe one named map
	int		line;
	int		col;
	int		available;

	line = 0;
	col = 0;
	available = 0;
	while (map[line] != NULL && map[line][col] != '.')
	{
		col = 0;
		while (map[line][col] != '\0' && map[line][col] == '#')
		{
			col++;
		}
		if (map[line][col] == '.')
		{
			if (map[line - 1][col] == '.' || map[line + 1][col] == '.'
			|| map[line][col - 1] == '.' || map[line][col + 1] == '.')
				available = 1;
		}
	if (available == 1)
		line++;
	}
	ft_();
	return (map);
}
