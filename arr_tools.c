/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:59:11 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/17 19:59:13 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//int g_num = 0;//Delete

void	free_list(t_map **list, int min_sq)
{
	int i;

	i = 0;
	// printf("DELETE:\t%d\n", (*list)->num);
	while (i < min_sq)
	{
		if ((*list)->map[i])
			free((*list)->map[i++]);
	}
	free((*list)->map);
	free((*list)->order);
	free(*list);
}

t_map	*backtrace(t_map **list, int min_sq)
{
	t_map *tmp;

	tmp = (*list)->next;
	free_list(list, min_sq);
	return (tmp);
}

void	free_all_list(t_map **list, int min_sq)
{
	while ((*list) != NULL)
		*list = backtrace(list, min_sq);
}

t_map	*ft_new_lst(int min_sq, int n_tetr)
{
//	g_num++;//Del
	t_map *tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->map = alloc_mem(min_sq);
	tmp->order = (char *)malloc(sizeof(char) * n_tetr);
	tmp->last_fig = 0;
	tmp->last_xy = 0;
//	tmp->num = g_num;
	tmp->next = NULL;
	// printf("NEW:\t%d\n", tmp->num);
	return (tmp);
}

t_map	*ft_add_link(t_map *list, int min_sq)
{
//	g_num++;//Del
	t_map *tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->map = copy_array(list->map, min_sq);
	tmp->order = list->order;
	tmp->last_fig = 0;
	tmp->last_xy = 0;
//	tmp->num = g_num;
	tmp->next = list;
	// printf("ADD:\t%d\n", tmp->num);
	return (tmp);
}
