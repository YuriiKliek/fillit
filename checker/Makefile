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

FLAGS = -Wall -Werror -Wextra 

SRCS = algorithm.c \
		arr_tools.c \
		conditions.c \
		fillit.c \
		get_next_line.c \
		main.c \
		print_map.c \
		tools.c \
		validator.c

OBJS = ./libft/libft.a

HEADER = fillit.h

NAME = fillit

all : $(NAME)

# $(NAME):
# 	gcc $(FLAGS) -o $(NAME) $(SRCS) $(OBJS) ./libft/libft.a

$(NAME):
	@make -C libft
	gcc $(FLAGS) -I $(HEADER) $(SRCS) $(OBJS) -o $(NAME) 

# $(NAME):
# 	gcc -o $(NAME) $(SRCS) $(OBJS) ./libft/libft.a

clean:
	@make clean -C libft
	@rm -f fillit.h.gch

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

ev:
	clear && make re && ./$(NAME) out.txt
# ev:
# 	clear && make re && .$(NAME) test.txt