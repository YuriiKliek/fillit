/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:52:17 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/04 17:52:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_free(t_fig fig, char **map, int *i, int min_sq)
{
	int	j;
	int x;
	int y;

	j = 1;
	while (j < 4)
	{
		x = i[2] + fig.p[j].x - fig.p[0].x;
		y = i[1] + fig.p[j].y - fig.p[0].y;
		if (x >= min_sq || y >= min_sq || x < 0 || y < 0)
			return (0);
		if (map[y][x] >= 'A' && map[x][y] <= 'Z')
			return (0);
		j++;
	}
	return (1);
}

char	**put_figure(t_fig fig, char **map, int i, int j)
{
	int count;
	int x;
	int y;

	count = 0;
	while (count < 4)
	{
		y = j + fig.p[count].x - fig.p[0].x;
		x = i + fig.p[count].y - fig.p[0].y;
		map[x][y] = 64 + fig.num;
		count++;
	}
	return (map);
}

void	cycle(t_map **list, t_fig *fig, int min_sq, int n_tetr)
{
	int		i[3];

	i[0] = ((*list)->last_fig > 0) ? (*list)->last_fig : 0;
	i[1] = ((*list)->last_xy == 0) ? 0 : (*list)->last_xy / min_sq;
	i[2] = ((*list)->last_xy == 0) ? 0 : (*list)->last_xy % min_sq;
	while (i[1] < min_sq)
	{
		while (i[2] < min_sq)
		{
			while (ft_strchr((*list)->order, i[0] + 65))
				i[0]++;
			if ((*list)->map[i[1]][i[2]] < 'A' || (*list)->map[i[1]][i[2]] > 'Z')
			{
				if (check_free(fig[i[0]], (*list)->map, i, min_sq) == 1)
				{
					*list = ft_add_link(*list, min_sq);
					(*list)->map = put_figure(fig[i[0]], (*list)->map, i[1], i[2]);
					(*list)->order = ft_joinc((*list)->order, 64 + fig[i[0]].num);
					(*list)->last_xy = i[1] * min_sq + i[2];
					int_zero(&i, 3);
				}
			}
			i[2]++;
		}
		i[1]++;
		i[2] = 0;
	}
	if ((int)ft_strlen((*list)->order) == n_tetr)
		print_map((*list)->map, min_sq);
}

void	alhorithmus(t_fig *fig, int n_tetr, int min_sq)
{
	t_map	*list;
	int 	tmp;
	int		last_fig;
	int		cur_fig;
	int 	last_xy;

	list = ft_new_lst(min_sq, n_tetr);
	cur_fig = 0;
	while (1)
	{
		cycle(&list, fig, min_sq, n_tetr);
		last_fig = cur_fig;
		cur_fig = (int)ft_strlen(list->order);
		if (cur_fig == n_tetr || (int)ft_strlen(list->order) == 0)
			break;
		else
		{
			tmp = list->order[cur_fig - 1] - 64;
			last_xy = list->last_xy;
			list = backtrace(&list, min_sq);
			if (last_fig > cur_fig || check_fig(list, fig[list->last_fig], min_sq, last_xy + 1) == 0)
			{
				list->last_fig = tmp;
				list->last_xy = 0;
			}
			else
				list->last_xy = last_xy + 1;
		}
	}
	free_all_list(&list, min_sq);
	if (cur_fig < n_tetr)
		alhorithmus(fig, n_tetr, min_sq + 1);
}

void	find_min_sq(t_fig *fig, int n_tetr)
{
	int min_sq;
	int min_area;

	min_area = 4 * n_tetr;
	min_sq = 0;
	while (min_sq * min_sq < min_area)
		min_sq++;
	alhorithmus(fig, n_tetr, min_sq);
}
