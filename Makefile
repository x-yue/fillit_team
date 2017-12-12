# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 23:46:58 by yuxu              #+#    #+#              #
#    Updated: 2017/12/11 20:50:14 by ablin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS =
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	ar rc $(NAME) *.o
	ramlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


##	change SRC, and change all the *
