/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:40:35 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/17 17:40:36 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_params(char **str)
{
	int	count;
	int	count_1;
	int	count_2;

	count = 0;
	count_2 = 0;
	while(str[count])
	{
		count_1 = 0;
		while (str[count][count_1] != '\0')
		{
			if (str[count][count_1] != '\n')
				count_2++;
			count_1++;
		}
		if (count_2 != 4)
			return (0);
		count++;
	}
	return (1);
}