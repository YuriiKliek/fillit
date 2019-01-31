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

char		**set_tetrimino(char *line, int count)
{
	int		count_1;
	char	**str;
	int		count_2;
	int		count_3;

	count_1 = 0;
	count_3 = 0;
	str = (char **)malloc((count - 3) / 4 + 1);
	while (line[count_1] != '\0')
	{
		count_2 = 0;
		str[count_3] = (char *)malloc(21);
		while(count_2 < 20)
		{
			str[count_3][count_2] = line[count_1];
			count_2++;
			count_1++;
		}
		str[count_3][count_2] = '\0';
		count_3++;
	}
	return (str);
}

char		**define_tetrimino(char **str)
{
	int		count;
	int		count_1;
	int		count_2;

	count = 0;
	count_2 = 65;
	while (str[count] != NULL)
	{
		count_1 = 0;
		while(str[count][count_1] != '\0')
		{
			if (str[count][count_1] == 35)
				str[count][count_1] = count_2;
			count_1++;
		}
		count++;
		count_2++;
	}
	return (str);
}

char		**draw_fill(char *file_name)
{
	int		fd;
	char	*line;
	char	**tab;
	char	*tmp;
	char	*str;
	int		count;

	count = 0;
	fd = open(file_name, O_RDONLY);
	str = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		line[4] = '\n';
		line[5] = '\0';
		tmp = ft_strjoin(str, line);
		free(str);
		str = tmp;
		count++;
	}
	printf("%s\n", str);
	tab = set_tetrimino(str, count);
	tab[(count - 3) / 4] =  0;
	tab = define_tetrimino(tab);
	return (tab);
}
