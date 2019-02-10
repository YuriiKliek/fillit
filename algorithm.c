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

//t_map	*cycle(t_map *list, t_fig *fig, int min_sq, int n_tetr)
//{
//	int		i[3];
//	t_map	*tmp;
//
//	i[0] = (list->last_fig > 0) ? list->last_fig + 1 : 0;
//	i[1] = -1;
//	while (++i[1] < min_sq)
//	{
//		i[2] = -1;
//		while (++i[2] < min_sq)
//		{
//			while (ft_strchr(list->order, i[0] + 65))
//				i[0]++;
//			if (list->map[i[1]][i[2]] < 'A' || list->map[i[1]][i[2]] > 'Z')
//			{
//				if (check_free(fig[i[0]], list->map, i, min_sq) == 1)
//				{
//					list->map = put_figure(fig[i[0]], list->map, i[1], i[2]);
//					list->order = ft_joinc(list->order, 64 + fig[i[0]].num);
////					print_map(list->map, min_sq);
////					printf("\n_________\n");
//					list = ft_add_link(list, min_sq);
//				}
//			}
//		}
//	}
////	if (i[0] == n_tetr)
////		print_map(list->map, min_sq);
//	return (list);
//}

void	cycle(t_map **list, t_fig *fig, int min_sq, int n_tetr)
{
	int		i[3];
	t_map	*tmp;

	i[0] = ((*list)->last_fig > 0) ? (*list)->last_fig + 1 : 0;
	i[1] = -1;
	print_map((*list)->map, min_sq);
	printf("\n_________\n");
	while (++i[1] < min_sq)
	{
		i[2] = -1;
		while (++i[2] < min_sq)
		{
			while (ft_strchr((*list)->order, i[0] + 65))
				i[0]++;
			if ((*list)->map[i[1]][i[2]] < 'A' || (*list)->map[i[1]][i[2]] > 'Z')
			{
				if (check_free(fig[i[0]], (*list)->map, i, min_sq) == 1)
				{
					(*list)->map = put_figure(fig[i[0]], (*list)->map, i[1], i[2]);
					(*list)->order = ft_joinc((*list)->order, 64 + fig[i[0]].num);
//					print_map((*list)->map, min_sq);
//					printf("\n_________\n");
					*list = ft_add_link(*list, min_sq);
				}
			}
		}
	}
//	if (i[0] == n_tetr)
//		print_map((*list)->map, min_sq);
}

void	alhorithmus(t_fig *fig, int n_tetr, int min_sq)
{
	t_map	*list;
	int		ret;

	list = ft_new_lst(min_sq, n_tetr);
	int z = 0;//
	while (z++ < 5)
	{
//		print_map(list->map, min_sq);
//		printf("\n_________\n");
//		if (list->next)
//		{
//			print_map(list->next->map, min_sq);
//			printf("\n_________\n");
//		}
//		list = ft_add_link(cycle(list, fig, min_sq, n_tetr), min_sq);
		cycle(&list, fig, min_sq, n_tetr);
//		printf("\nTMP: %d\n", list->last_fig);
//		printf("ORDER_LEN: %d\n", ret);
//		printf("%s\n", list->order);
//		printf("________________\n");
		if (ret == n_tetr)
			break;
		else
		{
//			printf("\e[1;31m");
//			print_map(list->map, min_sq);
//			printf("\n_________\n\e[1;32m");
			list = list->next;
//			print_map(list->map, min_sq);
//			printf("\n_________\n");
			ret = (int) ft_strlen(list->order);
			list->last_fig = list->order[ret - 1] - 65;
		}
	}
	if ((int)ft_strlen(list->order) < n_tetr)
		alhorithmus(fig, n_tetr, min_sq + 1);
//	if ((int)ft_strlen(list->order) == n_tetr)
//	{
//		while (list)
//		{
//			print_map(list->map, min_sq);
//			printf("\n\n\e[1;35m%s\e[1;33m\n\n", list->order);
//			list = list->next;
//		}
//	}
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
