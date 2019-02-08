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

#include <stdio.h>
#include "fillit.h"

int		main(int argc,char **argv)
{
	int fd;
	int fd2;
	int n_tetr;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[1], O_RDONLY);
		// printf("%d\n", open_file(fd, fd2));
		n_tetr = open_file(fd, fd2);
		printf("\e[1;36m%c = %d\e[1;32m\n", 64 + n_tetr, n_tetr); //Delete
		if (n_tetr > 0 && n_tetr <= 26)
		{
			fd = open(argv[1], O_RDONLY);
			draw_fill(fd, n_tetr);
		}
		else
			ft_putstr("error\n");
		close(fd);
		close(fd2);
	}
	else
		printf("Pass file's name\n"); //Delete
return (0);
}