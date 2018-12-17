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

void	printlst(t_list *head)
{
	while(head != NULL)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
}

int		main(int argc,char **argv)
{
	char **tab;
	int fd;

	// fd = 0;
	// if (argc == 2)
	// 	tab = draw_fill(argv[1]);
	// while (tab[fd] != NULL)
	// {
	// 	printf("%s", tab[fd]);
	// 	fd++;
	// }
	// printf("%s\n", tab[0]);
	// if (ft_strcmp(make_tamplete(), tab[0]) == 0)
	// 	printf("%s\n", "SUCCESS");
	// printf("%s\n", make_tamplete());
	printlst(make_tamplete());
	return (0);
}
