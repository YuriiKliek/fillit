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

char		**set_tetrimino(char *line)
{
	int		count;
	char	**result;
	int		tmp;
	int		count1;

	tmp = 0;
	count1 = 0;
	count = 0;
	while (line[count] != '\0')
		if (line[count++] == '\n')
			tmp++;
	result = (char **)malloc(sizeof(char *) * ((tmp / 5) + 1));
	count = tmp / 5;
	tmp = 0;
	while (count != -1)
	{
		result[tmp] = ft_strsub(line, 0, 20);
		tmp++;
		count--;
	}
	return (result);
}

char		**draw_fill(char *file_name)
{
	int		fd;
	int		count;
	char	*line;
	char	*line_tmp;
	char	**tab;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (!tab)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (count == 0)
			line_tmp = ft_strdup(line);
		if (count > 0)
			line_tmp = ft_strjoin(line_tmp, line);
		line_tmp = ft_strjoin(line_tmp, "\n");
		count++;
	}
	tab = set_tetrimino(line_tmp);
	return (tab);
}

int		main(int argc, char **argv)
{
	char	**tab;

	if (argc == 2)
		tab = draw_fill(argv[1]);
}
