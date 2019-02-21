// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   validator.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/12/17 17:40:35 by ykliek            #+#    #+#             */
// /*   Updated: 2018/12/17 17:40:36 by ykliek           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fillit.h"

// int		check_tetremino2(char **tab, int count)
// {
// 	int		i;
// 	int		i1;

// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		i1 = 0;
// 		while (tab[i][i1] != '\0')
// 		{
// 			if (tab[i][i1] == '#')
// 			{
// 				if (conditions(tab, i, i1, count) == 0)
// 					return (0);
// 				else if (conditions2(tab, i, i1, count) == 0)
// 					return (0);
// 				else if (conditions3(tab, i, i1, count) == 0)
// 					return (0);
// 			}
// 			i1++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int		check_tetremino(char **tab)
// {
// 	int		count;
// 	int		count1;
// 	int		count2;

// 	count = 0;
// 	count2 = 0;
// 	while (tab[count] != NULL)
// 	{
// 		count1 = 0;
// 		while (tab[count][count1] != '\0')
// 		{
// 			if (tab[count][count1] == '#')
// 				count2++;
// 			if (tab[count][count1] != '.' && tab[count][count1] != '#')
// 				return (0);
// 			count1++;
// 		}
// 		count++;
// 		if (count % 5 == 4)
// 		{
// 			if (count2 != 4)
// 				return (0);
// 			count2 = 0;
// 		}
// 	}
// 	return (1);
// }

// int		check_params(char *str)
// {
// 	int		count;

// 	count = 0;
// 	while (str[count] != '\0')
// 		count++;
// 	if (count != 4)
// 		return (0);
// 	return (1);
// }

// int		open_file(int fd)
// {
// 	char	**tab;
// 	char	*line;
// 	int		count;
// 	int		count_1;

// 	count_1 = 1;
// 	count = 0;
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		if (count_1 % 5 != 0)
// 		{
// 			if (check_params(line) == 0)
// 				return (0);
// 		}
// 		else if ((int)line[0] != 0)
// 			return (0);
// 		tab[count++] = line;
// 		count_1++;
// 	}
// 	tab[count] = NULL;
// 	if (check_tetremino(tab) == 0)
// 		return (0);
// 	if (check_tetremino2(tab, count) == 0)
// 		return (0);
// 	return (1);
// }