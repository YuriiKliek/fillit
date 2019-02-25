/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:11:06 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/25 19:11:08 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	check_fig(t_map *list, t_fig fig, int min_sq, int last_xy)
{
	int xy[3];

//	print_map(list->map, min_sq);
//	printf("\n_________\n");
	xy[1] = last_xy / min_sq;
	xy[2] = last_xy % min_sq;
	while (xy[1] < min_sq)
	{
		while (xy[2] < min_sq)
		{
			if (list->map[xy[1]][xy[2]] < 'A' || list->map[xy[1]][xy[2]] > 'Z')
			{
				if (check_free(fig, list->map, xy, min_sq) == 1)
					return (1);
			}
			xy[2]++;
		}
		xy[1]++;
		xy[2] = 0;
	}
	return (0);
}
