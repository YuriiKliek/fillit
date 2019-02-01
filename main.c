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

int     main(int argc,char **argv)
{
    int fd;
    int fd2;
    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        fd2 = open(argv[1], O_RDONLY);
        printf("%d\n", open_file(fd, fd2));
        close(fd);
        close(fd2);
    }
    else
        printf("Pass file's name\n");
    return (0);
}