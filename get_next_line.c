/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:16:00 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/08/16 16:57:56 by cyu-xian         ###   ########.fr       */
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
	char	*res;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	num = read(fd, book, BUFFER_SIZE);
	book[num] = '\0';
	while (num > 0)
	{
		temp = ft_strjoin(buffer, book); // 1 2 3 4 /0
		free(buffer); //0 buffer not malloc
		buffer = temp; //1 2 3 4 /0
		if (ft_strchr(buffer, '\n') != 0)
			break;
		num = read(fd, book, BUFFER_SIZE);
	}
	res = ft_strdup(buffer); //res is malloced
	// free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char 	*buffer;
	char	*temp;
	char	*retv;

	printf("BUFFER ON ENTER [%s]\n", buffer);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = mem_allocate(fd, buffer);
	// free(buffer);
	buffer = temp; // 1 2 3 4 /0 buffer is malloced (freed)
	if (ft_strchr(buffer, '\n') != 0)
	{
		retv = ft_substr(buffer, 0, new_line_finder(buffer) + 1); //retv is malloced 1 1 2 3 /0 (freed on outside)
		temp = ft_strdup(buffer + new_line_finder(buffer) + 1); //temp is malloced (freed)
		free(buffer);
		buffer = temp;
		free(temp); //freed here
	}
	else
		retv = buffer;
	if (retv[0] == '\0' && buffer[0] == '\0')
	{
		free(buffer); //buffer eof freed here
		buffer = NULL;
		return NULL;
	}
	return (retv);
}

int main()
{
	int fd = open("test.txt", 0);
	char *rv1;
	char *rv2;
	
	rv1 = get_next_line(fd);
	printf("rv1: %s\n", rv1);
	free(rv1);
	rv2 = get_next_line(fd);
	printf("rv2: %s\n", rv2);
	free(rv2);
	system("leaks a.out");
	return (0);
}