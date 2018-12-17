/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:25:28 by oorlov            #+#    #+#             */
/*   Updated: 2018/11/10 17:25:30 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int				new_line(char **str, char **line, int file_d, int result_read)
{
	char		*tmp;
	int			len;

	len = 0;
	while (str[file_d][len] != '\n' && str[file_d][len] != '\0')
		len++;
	if (str[file_d][len] == '\n')
	{
		*line = ft_strsub(str[file_d], 0, len);
		tmp = ft_strdup(str[file_d] + len + 1);
		free(str[file_d]);
		str[file_d] = tmp;
	}
	else if (str[file_d][len] == '\0')
	{
		if (result_read == BUFF_SIZE)
			return (get_next_line(file_d, line));
		*line = ft_strdup(str[file_d]);
		free(str[file_d]);
		str[file_d] = NULL;
	}
	return (1);
}

int				get_next_line(const int file_d, char **line)
{
	static char	*str[225];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			result_read;

	if (file_d < 0 || line == NULL)
		return (-1);
	while ((result_read = read(file_d, buf, BUFF_SIZE)) > 0)
	{
		buf[result_read] = '\0';
		if (str[file_d] == NULL)
			str[file_d] = ft_strnew(1);
		tmp = ft_strjoin(str[file_d], buf);
		free(str[file_d]);
		str[file_d] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (result_read < 0)
		return (-1);
	if (result_read == 0 && (str[file_d] == NULL || str[file_d][0] == '\0'))
		return (0);
	return (new_line(str, line, file_d, result_read));
}
