/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:39 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/07/23 17:50:48 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	new_line_finder(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int	i;
	static	char	*buffer;
	char	*retv;
	char	book[BUFFER_SIZE + 2];
	char	*temp;
	int		num;

	if (!buffer)
		buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
	
	printf("buffernew: %s\n", buffer);
	retv = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	num = 1;
	while (num > 0)
	{
		num = read(fd, book, BUFFER_SIZE);
		book[num] = '\0';
		printf("book: %s\n", book);
		i = 0;
		if (ft_strchr(book, '\n') == 0)
		{
			buffer = ft_strjoin(buffer, book);
			retv = buffer;
		}
		else
		{
			i = new_line_finder(book);
			retv = trimmer(i, buffer, book); //find \n; substr it; return it
			buffer = ft_strjoin(buffer, book);
			buffer = ft_strdup(book + 1 + i);
			temp = ft_strdup(retv);
			free(retv);
			return(temp);
		}
	}
	return (retv);
}

// int main()
// {
// 	int fd = open("test.txt", 0);
// 	printf("rv1: %s\n", get_next_line(fd));
// 	printf("rv2: %s\n", get_next_line(fd));
// 	return (0);
// }