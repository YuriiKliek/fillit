/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:31:47 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/08 20:31:48 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_joinc(const char *s, const char c)
{
	char	*d;
	int		i;

	i = -1;
	if (s && c)
	{
		if (!(d = ft_strnew(ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i] != '\0')
			d[i] = s[i];
		d[i] = c;
		d[i + 1] = '\0';
		return (d);
	}
	return (NULL);
}

char	**alloc_mem(int min_sq)
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

t_map	*ft_new_lst(int min_sq, int n_tetr)
{
	t_map *tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->map = alloc_mem(min_sq);
	tmp->order = (char *)malloc(sizeof(char) * n_tetr);
	tmp->last_fig = 0;
	tmp->num = 0;
	tmp->next = NULL;
	return (tmp);
}

char	**copy_array(char **s, int min_sq)
{
	char	**d;
	int		i;
	int		j;

	d = (char **)malloc(sizeof(char *) * 169);
	i = 0;
	while (i < min_sq)
	{
		j = 0;
		d[i] = (char *)malloc(sizeof(char) * 13);
		while (j < min_sq)
		{
			d[i][j] = s[i][j];
			j++;
		}
//		d[i][j] = '\0';
		i++;
	}
	return (d);
}

t_map	*ft_add_link(t_map *list, int min_sq)
{
	t_map *tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
//	tmp->map = list->map;
	tmp->map = copy_array(list->map, min_sq);
	tmp->order = list->order;
	tmp->last_fig = 0;
	tmp->num = list->num + 1;
	tmp->next = list;
	return (tmp);
}
