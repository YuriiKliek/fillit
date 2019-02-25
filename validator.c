/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:40:35 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/17 17:40:36 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_lines(char **tab)
{
	int		count;
	int		count1;
	int		count2;

	count = 0;
	count2 = 0;
	while (tab[count] != NULL)
	{
		count1 = 0;
		while (tab[count][count1] != '\0')
		{
			if (tab[count][count1] == '#')
				count2++;
			if (tab[count][count1] != '.' && tab[count][count1] != '#')
				return (0);
			count1++;
		}
		count++;
		if (count % 5 == 4)
		{
			if (count2 != 4)
				return (0);
			count2 = 0;
		}
	}
	return (1);
}

static int	find_count(int	fd)
{
	int		count;
	char	*str;

	count = 0;
	while (get_next_line(fd, &str) == 1)
	{
		count++;
		free(str);
	}
	return (count);
}

int			check_params(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	if (count != 4)
		return (0);
	return (1);
}

int			open_file(int fd, int fd2)
{
	char	**tab;
	char	*line;
	int		count;
	int		count_1;

	count_1 = 1;
	count = 0;
	tab = (char **)malloc(sizeof(char*) * (find_count(fd2) + 1) * 6);
	while (get_next_line(fd, &line) == 1)
	{
		if (count_1 % 5 != 0)
		{
			if (check_params(line) == 0)
				return (0);
		}
		else if ((int)line[0] != 0)
			return (0);
		tab[count++] = ft_strdup(line);
		count_1++;
		ft_strdel(&line);
	}
	if (count % 5 != 4)
		return (0);
	tab[count] = NULL;
	if (check_lines(tab) == 0)
		return (0);
	int l = 0;
	while (l < count)
		ft_strdel(&tab[l++]);
	free(tab);
	// free_mem(&tab, &line, count);
	return ((count + 1) / 5);
}