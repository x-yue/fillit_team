# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 23:46:58 by yuxu              #+#    #+#              #
#    Updated: 2018/01/20 05:45:52 by ablin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = src/
SRCS = src/read.c src/solve.c src/move.c src/map.c
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc src/main.c -o $(NAME) $(FLAGS) $(SRCS) -L. lib/libft.a

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
