# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 00:27:39 by iel-ferk          #+#    #+#              #
#    Updated: 2019/09/15 01:45:01 by iel-ferk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c check_file.c position.c output.c solve.c
OBJS = main.o check_file.o position.o output.o solve.o
HEAD = fillit.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEAD)
	gcc -c $(FLAG) $(SRCS)
	gcc $(FLAG) $(OBJS) -o $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
