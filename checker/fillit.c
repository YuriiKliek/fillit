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
	tmp.num = order;
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
	int		i[3];
	t_fig	fig[n_tetr];

	i[0] = 0;
	i[1] = 0;
	tab = (char **)malloc(sizeof(char*) * 4 * 6);
	while (get_next_line(fd, &line) == 1)
	{
		if (i[0] != 4)
			tab[i[0]] = ft_strdup(line);
		i[0] = (i[0] != 4) ? i[0] + 1 : 0;
		if (i[0] == 4)
		{
			fig[i[1]] = process_figure(tab, i[1] + 1);
			i[1]++;
			i[2] = 0;
			while (i[2] < i[0])
				ft_strdel(&tab[i[2]++]);
		}
		ft_strdel(&line);
	}
	free(tab);
	find_min_sq(fig, n_tetr);
}