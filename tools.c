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

void	print_list(t_map *list)
{
	printf("\n");
	while (list)
	{
		printf("order:\t%s\n", list->order);
		list = list->next;
	}
	printf("\n");
}

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
		i++;
	}
	return (d);
}

int 	free_mem(char ***tab, char **line, int count)
{
	// int i;

	// i = 0;
	// if (*line)
	// 	ft_strdel(line);
	// while (i < count)
	// 	ft_strdel(tab[i++]);
	// free(*tab);
	int l = 0;
	while (l < count)
	{
		if (tab[l])
			printf("%s\n", *tab[l]);
			ft_strdel(tab[l++]);
	}
	free(*tab);
	return (0);
}

void	int_zero(void *num, size_t n)
{
	int		*str;
	int		i;
	int		count;

	i = (int)n;
	str = (int*)num;
	count = 0;
	while (count < i)
	{
		str[count] = '\0';
		count++;
	}
	num = str;
}