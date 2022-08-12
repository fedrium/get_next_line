/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:16:00 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/08/10 16:13:43 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	new_line_finder(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' )//|| line[i] != '\0' || !(line[i]))
		i++;
	return (i);
}

char	*mem_allocate(int fd, char *buffer)
{
	char	*temp;
	int		num;
	char	book[BUFFER_SIZE + 1];

	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
	}	
	if (num > 0)
	{
		book[num] = '\0';
		temp = ft_strjoin(buffer, book);
		free(buffer);
		buffer = temp;
		if (ft_strchr(buffer, '\n'))
			break;
		num = book(fd, book, BUFFER_SIZE);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char 	buffer;
	char	*temp;
	char	*retv;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = mem_allocate(fd, buffer);
	free(buffer);
	buffer = temp;
	if (ft_strchr(buffer, '/n'))
	{
		retv = ft_substr(buffer, 0, new_line_finder(buffer));
		temp = ft_strdup(buffer + i + 1);
		free(buffer);
		buffer = temp;
	}
	else
		retv = buffer;
	if (buffer[0] == NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	return (retv);
}