/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:27:18 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 06:16:53 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef	struct		s_tetri
{
	char			**board;
	char			letter;
	int				x;
	int				y;
	struct s_tetri	*next;
	struct s_tetri	*prev;
	struct s_tetri	*start;
}					t_tetri;

typedef	struct		s_double
{
	t_tetri			*tail;
	t_tetri			*head;
}					t_double;

typedef	struct		s_pos
{
	int				x[4];
	int				y[4];
}					t_pos;

typedef	struct		s_fit
{
	int				line;
	int				col;
	int				count;
}					t_fit;

typedef	struct		s_file
{
	int				fd;
	int				rd;
	int				tetrinb;
	int				end;
	char			buf[21];
}					t_file;

typedef	struct		s_move
{
	int				i;
	int				line;
	int				hashtag_count;
	int				mv_up;
	int				mv_l;
	int				n;
	int				k[4];
	char			**tmp;
}					t_move;

t_double			*ft_lsttetri(t_double *lst, char **board, int tetrinb);
t_tetri				*ft_tetripos(t_tetri *tetri, int size);
t_pos				ft_pos(char **board);
void				ft_showtab(char **board);
char				**ft_board(char *str);
char				**malloc_it(void);
char				**ft_swap_up(char **board, int line, int i, int mv_up);
char				**ft_left(char **board);
char				**ft_united(char **board);
char				**ft_map(char **map, int size);
char				**ft_set(int size);
char				**ft_insert(char **map, t_tetri *tetri, int line, int col);
char				**ft_erase(char **map, char letter);
char				**ft_unfit(t_tetri *tetri, char **map, int size);
char				**ft_fit(t_tetri *tetri, t_pos pos, int size);
int					ft_check(char *str);
int					ft_minsize(int tetrinb);
int					ft_read(char *filename);
int					first_left(char **board);
int					ft_checkpos(t_tetri *tetri, t_fit fit, char **map,
																	int size);

#endif
