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

int			check_point(t_fig fig, int j, int k)
{
	t_point pj;
	t_point pk;

	pj.x = fig.p[j].x;
	pj.y = fig.p[j].y;
	pk.x = fig.p[k].x;
	pk.y = fig.p[k].y;
	if (pj.x == pk.x + 1 && pj.y == pk.y)
		return (1);
	if (pj.x == pk.x - 1 && pj.y == pk.y)
		return (1);
	if (pj.y == pk.y + 1 && pj.x == pk.x)
		return (1);
	if (pj.y == pk.y - 1 && pj.x == pk.x)
		return (1);
	return (0);
}

int			check_figures(t_fig *fig, int n_tetr)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	while (i < n_tetr)
	{
		count = 0;
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (check_point(fig[i], j, k) == 1)
					count++;
				k++;
			}
			j++;
		}
		if (count < 6)
			return (0);
		i++;
	}
	return (1);
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

int			draw_fill(int fd, int n_tetr)
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
	if (check_figures(fig, n_tetr) == 0)
		return (0);
	find_min_sq(fig, n_tetr);
	return (1);
}
