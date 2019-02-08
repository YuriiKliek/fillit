/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:17:35 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/15 15:17:36 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_struct(t_fig *tmp, int n_tetr)
{
	int		count;
	int		i;

	count = 0;
	while (count < n_tetr)
	{
		printf("ORDER: %d\n", tmp[count].order);
		i = 0;
		while (i < 4)
		{
			printf("xy%d [%d: %d]\n", i, tmp[count].p[i].x, tmp[count].p[i].y);
			i++;
		}
		count++;
	}
}

void		move_to_start(t_fig *tmp)
{
	int min_x;
	int min_y;
	int i;

	i = 0;
	min_x = 4;
	min_y = 4;
	while (i < 4)
	{
		if (tmp->p[i].x < min_x)
			min_x = tmp->p[i].x;
		if (tmp->p[i].y < min_y)
			min_y = tmp->p[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tmp->p[i].x -= min_x;
		tmp->p[i].y -= min_y;
		i++;
	}
}

t_fig		process_figure(char **str, int order)
{
	int		x;
	int		y;
	int		count;
	t_fig	tmp;

	x = 0;
	count = 0;
	tmp.order = order;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (str[x][y] == '#')
			{
				tmp.p[count].x = y;
				tmp.p[count].y = x;
				count++;
			}
			y++;
		}
		x++;
	}
	move_to_start(&tmp);
	return (tmp);
}

void		draw_fill(int fd, int n_tetr)
{
	char	*line;
	char	**tab;
	int		i;
	int		count;
	t_fig	fig[n_tetr];

	i = 0;
	count = 0;
	tab = (char **)malloc(sizeof(char*) * 4 * 6);
//	fig = (t_fig*)malloc(sizeof(t_fig) * n_tetr);
	while (get_next_line(fd, &line) == 1)
	{
		if (i != 5)
			tab[i] = ft_strdup(line);
		i = (i != 4) ? i + 1 : 0;
		if (i == 4)
		{
			fig[count] = process_figure(tab, count + 1);
			count++;
			int l = 0;
			while (l < i)
				ft_strdel(&tab[l++]);
		}
		ft_strdel(&line);
	}
	free(tab);
	// print_struct(fig, n_tetr);
	find_min_sq(fig, n_tetr);
}