# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oorlov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 20:39:03 by oorlov            #+#    #+#              #
#    Updated: 2018/12/02 20:39:04 by oorlov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

HEADER = libft.h

SRCS = *.c

OBJS = *.o

all : $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -I  $(HEADER)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f *.o 

fclean: clean
	rm -f $(NAME)

re: fclean all

