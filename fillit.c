/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:40:07 by oorlov            #+#    #+#             */
/*   Updated: 2018/12/03 13:40:09 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**draw_fill(char *file_name)
{
	int		fd;
	int		count;
	char	*line;
	char	**tab;

	count = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
		count++;
	fd = open(file_name, O_RDONLY);
	tab = (char **)malloc(sizeof(char *) * (count) + 1);
	if (!tab)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		tab[count] = ft_strdup(line);
		count++;
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	char	**tab;

	if (argc == 2)
		tab = draw_fill(argv[1]);
}
