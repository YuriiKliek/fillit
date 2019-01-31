/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:16:41 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/15 15:16:43 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include "fillit.h"
//#include <time.h>

//void	printlst(t_list *head)
//{
//	while(head != NULL)
//	{
//		printf("%s\n", head->content);
//		head = head->next;
//	}
//}
//
//int		main(int argc,char **argv)
//{
//	char **tab;
//	// int fd;
//
//	// fd = 0;
//	// if (argc == 2)
//		tab = draw_fill(argv[1]);
//	// while (tab[fd] != NULL)
//	// {
//	// 	printf("%s", tab[fd]);
//	// 	fd++;
//	// }
//
//	// printf("%s\n", tab[0]);
//	// if (ft_strcmp(make_tamplete(), tab[0]) == 0)
//	// 	printf("%s\n", "SUCCESS");
//	// printf("%s\n", make_tamplete());
//	//printlst(make_tamplete());
//	return (0);
//}

#include "fillit.h"
#include <time.h>


typedef	struct	s_point
{
    int x;
    int y;
}				t_point;

typedef	struct	s_figure
{
    t_point p[4];
}				t_figure;

int		ft_new_coord(t_point b, int drct, int coord)
{
    if (coord == 1) // y
    {
        if (drct == 0)
            return  (b.y - 1);
        else if (drct == 2)
            return (b.y + 1);
        else
            return (b.y);
    }
    else if (coord == 0) // x
    {
        if (drct == 1)
            return (b.x + 1);
        else if (drct == 3)
            return (b.x - 1);
        else
            return (b.x);
    }
    return (-1);
}

int		validate(t_point a, int drct)
{
    if (drct == 0 && a.y == 0)
        return (0);
    else if (drct == 2 && a.y == 3)
        return (0);
    else if (drct == 1 && a.x == 3)
        return (0);
    else if (drct == 3 && a.x == 0)
        return (0);
    return (1);
}

void	generate(void)
{
    t_figure	f;
    int			count;
    int			drct;
    int			i;
    int			j;
    char		map[4][4];

    count = 0;
    f.p[0].x = rand() % 4;
    f.p[0].y = rand() % 4;
    map[f.p[0].x][f.p[0].y] = '#';
    while (count < 3)
    {
        drct = rand() % 4;
        if (validate(f.p[count], drct) == 1)
        {
            f.p[count + 1].x = ft_new_coord(f.p[count], drct, 0);
            f.p[count + 1].y = ft_new_coord(f.p[count], drct, 1);
            if (map[f.p[count + 1].x][f.p[count + 1].y] != '#')
            {
                map[f.p[count + 1].x][f.p[count + 1].y] = '#';
                count++;
            }
        }
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (map[i][j] != '#')
                map[i][j] = '.';
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
            printf("%c", map[i][j++]);
        printf("\n");
        i++;
    }
}

void	generate_write(int fd)
{
    t_figure	f;
    int			count;
    int			drct;
    int			i;
    int			j;
    char		map[4][4];

    count = 0;
    f.p[0].x = rand() % 4;
    f.p[0].y = rand() % 4;
    map[f.p[0].x][f.p[0].y] = '#';
    while (count < 3)
    {
        drct = rand() % 4;
        if (validate(f.p[count], drct) == 1)
        {
            f.p[count + 1].x = ft_new_coord(f.p[count], drct, 0);
            f.p[count + 1].y = ft_new_coord(f.p[count], drct, 1);
            if (map[f.p[count + 1].x][f.p[count + 1].y] != '#')
            {
                map[f.p[count + 1].x][f.p[count + 1].y] = '#';
                count++;
            }
        }
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (map[i][j] != '#')
                map[i][j] = '.';
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        j = 0;
        while (j < 4)
            write(fd, &map[i][j++], 1);
        write(fd, "\n", 1);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int		count;
    int fd;
    srand(time(0));

    if (argc == 1)
    {
        printf("ARGC:\t1\n");
        count = 15;
        while (count-- > 0)
        {
            generate();
            printf("\n");
        }
    }

    if (argc == 2)
    {
//        printf("ARGC:\t2\n");
        count = ft_atoi(argv[1]);
        while (count-- > 0)
        {
            generate();
            printf("\n");
        }
    }
    if (argc == 3)
    {
        printf("ARGC:\t3\n");
        fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
        count = ft_atoi(argv[2]);
        while (count-- > 0)
        {
//            write(fd, "Hi\n", 3);
            generate_write(fd);
            if (count != 1)
                write(fd, "\n", 1);
        }
        close (fd);
    }
    return (0);
}
