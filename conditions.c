/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:32:56 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/25 11:32:58 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_count(char **tab, int i, int i2)
{
	int count;
	int	count_1;

	count_1 = 0;
	count = 0;
	while (tab[i + 1][count] != '\0')
	{
		if (tab[i + 1][count] == '#')
			count_1++;
		count++;
	}
	return (count_1);
}

int		conditions4(char **tab, int i, int i2)
{
	int count;
	int	count_1;

	count_1 = find_count(tab, i, i2);
	count = 0;
	i = i + 2;
	if (count_1 == 0)
	{
		while (i % 5 != 4)
		{
			count_1 = 0;
			while (tab[i][count_1] != '\0')
			{
				if (tab[i][count_1] == '#')
					count++;
				count_1++;
			}
			i++;
		}
		if (count != 0)
			return (0);
	}
	return (1);
}

int		conditions2(char **a, int i, int i2, int count)
{
	if (i == 0 && i2 != 0 && i2 != 3)
	{
		if (a[i][i2 + 1] != '#' && a[i + 1][i2] != '#' && a[i][i2 - 1] != '#')
			return (0);
	}
	else if (i2 == 0 && i != 0 && i != (count - 1))
	{
		if (a[i][i2 + 1] != '#' && a[i + 1][i2] != '#' && a[i - 1][i2] != '#')
			return (0);
	}
	else if (i == (count - 1) && i2 != 0 && i2 != 3)
	{
		if (a[i][i2 + 1] != '#' && a[i][i2 - 1] != '#' && a[i - 1][i2] != '#')
			return (0);
	}
	else if (i2 == 3 && i != 0 && i != (count - 1))
	{
		if (a[i + 1][i2] != '#' && a[i][i2 - 1] != '#' && a[i - 1][i2] != '#')
			return (0);
	}
	return (1);
}

int		conditions(char **a, int i, int i2, int count)
{
	if (i == 0 && i2 == 0)
	{
		if (a[i][i2 + 1] != '#' && a[i + 1][i2] != '#')
			return (0);
	}
	else if (i == 0 && i2 == 3)
	{
		if (a[i + 1][i2] != '#' && a[i][i2 - 1] != '#')
			return (0);
	}
	else if (i == (count - 1) && i2 == 0)
	{
		if (a[i][i2 - 1] != '#' && a[i][i2 + 1] != '#')
			return (0);
	}
	else if (i == (count - 1) && i2 == 3)
	{
		if (a[i][i2 - 1] != '#' && a[i - 1][i2] != '#')
			return (0);
	}
	return (1);
}

int		conditions3(char **a, int i, int i2, int count)
{
	if (i != 0 && i2 != 0 && i != (count - 1) && i2 != 3)
	{
		if (a[i + 1][i2] != '#' && a[i][i2 + 1]
			&& a[i][i2 - 1] != '#' && a[i - 1][i2] != '#')
			return (0);
	}
	if (conditions4(a, i, i2) == 0)
		return (0);
	return (1);
}