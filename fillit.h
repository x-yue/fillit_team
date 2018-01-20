/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:27:18 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 05:25:08 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"


typedef	struct	s_tetri
{
	char	**board;
	char	letter;
	int		x;
	int		y;
	struct	s_tetri	*next;
	struct	s_tetri	*prev;
	struct	s_tetri	*start;
}				t_tetri;

typedef	struct	d_list
{
		t_tetri	*tail;
		t_tetri	*head;
}				y_list;

typedef	struct	struct_pos
{
	int		x[4];
	int		y[4];
}			s_pos;

typedef	struct	fit_struct
{
	int				line;
	int				col;
	int				count;
}				it_struct;

typedef	struct	file_struct
{
	int		fd;
	int		rd;
	int		tetrinb;
	int		end;
	char	buf[21];
}				f_struct;

typedef	struct	united_struct
{
	int		i;
	int		line;
	int		hashtag_count;
	int		mv_up;
	int		mv_l;
	char	**tmp;
	int		n;
	int		k[4];
}				nb_list;

//read
y_list	*ft_lsttetri(y_list *lst, char **board, int tetrinb);
char	**ft_board(char *str);
int		ft_check(char *str);
int		ft_read(char *filename);

//move
char	**malloc_it(void);
char	**ft_swap_up(char **board, int line, int i, int mv_up);
int		first_left(char **board);
char	**ft_left(char **board);
char	**ft_united(char **board);

//map
char	**ft_map(char **map, int size);
char	**ft_set(int size);
char	**ft_insert(char **map, t_tetri *tetri, int line, int col);
void	ft_showtab(char **board);

//solve
t_tetri	*ft_tetripos(t_tetri *tetri, int size);
char	**ft_unfit(t_tetri *tetri, char **map, int size);
int		ft_checkpos(t_tetri *tetri, it_struct *fit, char **map, int size);
char	**ft_fit(t_tetri *tetri, s_pos pos, int size);
s_pos	ft_getpos(char **board);
#endif
