/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:31:47 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/08 20:31:48 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_joinc(const char *s, const char c)
{
	char	*d;
	int		i;

	i = -1;
	if (s && c)
	{
		if (!(d = ft_strnew(ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i] != '\0')
			d[i] = s[i];
		d[i] = c;
		d[i + 1] = '\0';
		return (d);
	}
	return (NULL);
}
