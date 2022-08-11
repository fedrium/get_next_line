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

char	*trimmer(int fd, char *buffer)
{
	char	book[BUFFER_SIZE + 1];
	char	temp;
	int		num;


	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		buffer[0] = '\0';
	}
	num = book(fd, book, BUFFER_SIZE);
	book[num] = '\0';
	if (num > 0)
	{
		temp = ft_strjoin(buffer, book);
		free(buffer);
		buffer = temp;
	}
}

char	*get_next_line(int fd)
{
	int	i;
	static char	buffer;
	char	*retv;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = trimmer(buffer);
}