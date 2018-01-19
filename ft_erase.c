/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:46:22 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/19 23:34:32 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

char	**ft_erase(char **map, char letter)
{
	int	line;
	int col;

	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\n')
		{
			if (map[line][col] == letter)
				map[line][col] = '.';
			col++;
		}
		line++;
	}
	return (map);
}

char	**ft_clean(char **map)
{
	int	line;
	int col;

	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\n')
		{
			if (map[line][col] != '.')
				map[line][col] = '.';
			col++;
		}
		line++;
	}
	return (map);
}
