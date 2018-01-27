# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 23:46:58 by yuxu              #+#    #+#              #
#    Updated: 2018/01/27 00:08:03 by ablin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = src/read.c src/solve.c src/move.c src/map.c
FLAGS = -Wall -Wextra -Werror
OBJ = read.c solve.c move.c map.c
OBJS = $(OBJ:.c=.o)

all: $(NAME)

$(NAME):
	cd lib/ && make re
	gcc -c $(FLAGS) $(SRCS)
	gcc src/main.c -o $(NAME) $(OBJS) lib/libft.a

clean:
	/bin/rm -f $(OBJS)
	cd lib/ && make clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f lib/libft.a
	cd lib/ && make fclean

re: fclean all
