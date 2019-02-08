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
		// if (map[x][y] >= 'A' && map[x][y] <= 'Z')
//		if (map[x][y] >= 'A' && map[x][y] <= 'Z')
		if (map[y][x] >= 'A' && map[x][y] <= 'Z')
		{
			// printf("\e[1;35m%c\e[1;32m\n", map[x][y]);
			return (0);
		}
		j++;
	}
	return (1);
}

char	**alloc_mem(int min_sq, int n_tetr)
{
	int		i;
	char	**map;

	map = (char **)malloc(sizeof(char *) * min_sq * min_sq);
	i = 0;
	while (i < min_sq)
	{
		map[i] = (char *)malloc(sizeof(char) * min_sq);
		i++;
	}
	return (map);
}

char	**put_figure(t_fig fig, char **map, int i, int j)
// char	**put_figure(t_fig fig, char **map, int i, int j, int min_sq)
{
	int count;
	int x;
	int y;

	count = 0;
	while (count < 4)
	{
		y = j + fig.p[count].x - fig.p[0].x;
		x = i + fig.p[count].y - fig.p[0].y;
		map[x][y] = 64 + fig.order;


		// print_map(map, min_sq); //delete
		// printf("\n\n");


		count++;
	}
	return (map);
}


void	alhorithmus(t_fig *fig, int n_tetr, int min_sq)
{
	int i[3];
	t_map list;

	i[0] = 0;
	list.map = alloc_mem(min_sq, n_tetr);
	list.order = (char *)malloc(sizeof(char) * n_tetr);
	i[1] = 0;
	while (i[1] < min_sq)
	{
		i[2] = 0;
		while (i[2] < min_sq)
		{
			if (list.map[i[1]][i[2]] < 'A' || list.map[i[1]][i[2]] > 'Z')
			{
				// printf("\e[1;31mFIG #%d\n", i[0]);
				// printf("\e[1;33mmap[%d][%d]\e[1;32m\n", i[1], i[2]);
				if (check_free(fig[i[0]], list.map, i, min_sq) == 1)
				{
					list.map = put_figure(fig[i[0]], list.map, i[1], i[2]);
					// list.map = put_figure(fig[i[0]], list.map, i[1], i[2], min_sq);
					char c = 64 + fig[i[0]].order;
					list.order = ft_joinc(list.order, c);
					printf("%s\n", list.order);
					i[0]++;
				}
			}
			i[2]++;
		}
		i[1]++;
	}
	if (i[0] < n_tetr)
		alhorithmus(fig, n_tetr, min_sq + 1);
	else
		print_map(list.map, min_sq);
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
