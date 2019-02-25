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

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1

typedef struct  s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_fig
{
	t_point	p[4];
	int		num;
}				t_fig;

typedef struct  s_map
{
	char			**map;
	char			*order;
	int 			last_fig;
	int 			last_xy;
	char 			to_move;
	struct s_map	*next;
}				t_map;

int			get_next_line(const int a, char **b);

int			draw_fill(int fd, int n_tetr);

void		find_min_sq(t_fig *fig, int n_tetr);

int			open_file(int fd, int fd2);

int			check_params(char *str);


void		print_map(char **map, int sq);

char		*ft_joinc(const char *s, const char c);

char		**alloc_mem(int min_sq);

char		**copy_array(char **s, int min_sq);

t_map		*ft_new_lst(int min_sq, int n_tetr);


//t_map		*ft_add_link(t_map *list);
t_map		*ft_add_link(t_map *list, int min_sq);
//t_map		*ft_add_link(t_map *list, int min_sq, int n_tetr);

// void		free_list(t_map **list);
void		free_list(t_map **list, int min_sq);
t_map		*backtrace(t_map **list, int min_sq);
void		free_all_list(t_map **list, int min_sq);

void		print_list(t_map *list);//

int 		free_mem(char ***tab, char **line, int count);

void		int_zero(void *num, size_t n);

int			check_fig(t_map *list, t_fig fig, int min_sq, int last_xy);

int			check_free(t_fig fig, char **map, int *i, int min_sq);

int 	*set_int(int *count, int set1, int set2);

#endif