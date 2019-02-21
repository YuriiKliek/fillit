/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:19:04 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/08 15:19:06 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int sq)
{
	int i;
	int j;

	i = 0;
	while (i < sq)
	{
		j = 0;
		while (j < sq)
		{
			if (map[i][j] < 'A' || map[i][j] > 'Z')
				ft_putchar('.');
			else
				ft_putchar(map[i][j]);
			j++;
		}
		if (i < sq - 1)
			ft_putchar('\n');
		i++;
	}
}
