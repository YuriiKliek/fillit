/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:40:39 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/31 13:40:41 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../fillit.h"
//#include <time.h>
//
//
//typedef	struct	s_point
//{
//	int x;
//	int y;
//}				t_point;
//
//typedef	struct	s_figure
//{
//	t_point p[4];
//}				t_figure;
//
//int		ft_new_coord(t_point b, int drct, int coord)
//{
//	if (coord == 1) // y
//	{
//		if (drct == 0)
//			return  (b.y - 1);
//		else if (drct == 2)
//			return (b.y + 1);
//		else
//			return (b.y);
//	}
//	else if (coord == 0) // x
//	{
//		if (drct == 1)
//			return (b.x + 1);
//		else if (drct == 3)
//			return (b.x - 1);
//		else
//			return (b.x);
//	}
//	return (-1);
//}
//
//int		validate(t_point a, int drct)
//{
//	printf("DRCT:\t%d\n", drct);
//	if (drct == 0 && a.y == 0)
//		return (0);
//	else if (drct == 2 && a.y == 3)
//		return (0);
//	else if (drct == 1 && a.x == 3)
//		return (0);
//	else if (drct == 3 && a.x == 0)
//		return (0);
//	return (1);
//}
//
//void	ft_putmap(char **map)
//{
//	int i;
//
//	i = 0;
//	while (i < 4)
//		printf("%s\n", map[i++]);
//}
//
//void	generate(void)
//{
//	t_figure	f;
//	int			count;
//	int			drct;
//	int			i;
//	int			j;
//	char		map[4][4];
//
//	count = 0;
//	f.p[0].x = rand() % 4;
//	f.p[0].y = rand() % 4;
//	map[f.p[0].x][f.p[0].y] = '#';
//	printf("[%d][%d]\n", f.p[0].x, f.p[0].y);
//	while (count < 4)
//	{
//		drct = rand() % 4;
//		if (validate(f.p[count], drct) == 1)
//		{
//			f.p[count].x = ft_new_coord(f.p[count], drct, 0);
//			f.p[count].y = ft_new_coord(f.p[count], drct, 1);
//			printf("[%d][%d]\n", f.p[count].x, f.p[count].y);
//			if (map[f.p[count].x][f.p[count].y] != '#')
//			{
//				map[f.p[count].x][f.p[count].y] = '#';
//				count++;
//			}
//		}
//	}
//	i = 0;
//	while (i < 4)
//	{
//		j = 0;
//		while (j < 4)
//		{
//			if (map[i][j] != '#')
//				map[i][j] = '.';
//			j++;
//		}
//		i++;
//	}
//	// ft_putmap(map);
//	i = 0;
//	while (i < 4)
//	{
//		j = 0;
//		while (j < 4)
//			printf("%c", map[i][j++]);
//		printf("\n");
//		i++;
//	}
//}
//
//int main(int argc, char const *argv[])
//{
//	int		count;
//	srand(time(0));
//
//	if (argc == 2)
//	{
//		count = ft_atoi(argv[1]);
//		while (count-- > 0)
//		{
//			generate();
//			printf("\n");
//		}
//	}
//	return (0);
//}
