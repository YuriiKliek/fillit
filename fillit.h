/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:27:44 by oorlov            #+#    #+#             */
/*   Updated: 2018/12/04 15:27:47 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "./libft/libft.h"

# define BUFF_SIZE 1

int		get_next_line(const int a, char **b);

int		new_line(char **a, char **b, int c, int d);

char		**set_tetrimino(char *line, int count);

char		**draw_fill(char *file_name);

char		**define_tetrimino(char **str);

t_list		*make_tamplete();

t_list		*make_tamplete1();

t_list		*make_tamplete2();

t_list		*make_tamplete3();

void		printlst(t_list *head);

#endif