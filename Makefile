# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oorlov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 20:39:03 by oorlov            #+#    #+#              #
#*   Updated: 2018/12/10 16:53:02 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

HEADER = libft.h

SRCS = *.c

OBJS = *.h

NAME = execute

all : $(NAME)

$(NAME):
	gcc $(SRCS) $(OBJS) ./libft/libft.a

clean:
	rm -f a.out fillit.h.gch execute

fclean: clean
	rm -f $(NAME)

re: fclean all

