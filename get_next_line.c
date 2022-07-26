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
	i = 0;
	num = 1;
	while (num > 0)
	{
		num = read(fd, book, BUFFER_SIZE);
		book[num] = '\0';
		printf("book: %s\n", book);
		// i = 0;
		// while (i <= num)
		// {
			// if (i == num - 1 && (book[i] != '\n' || book[i] == '\0'))
			if (ft_strchr(book, "\n") == 0)
			{
				// retv = ft_strjoin(retv, book);
				// retv = ft_strjoin(buffer, retv);
				buffer = ft_strjoin(buffer, book);
			}
			// if (book[i] == '\n')
			else
			{
				// retv = trimmer(retv, i, book, buffer); //find \n; substr it; return it
				buffer = ft_strjoin(buffer, book);
				retv = 
				printf("retv: %s\n", retv);
				buffer = ft_strdup(book + 1 + i);
				printf("buffer: %s\n", buffer);
				temp = ft_strdup(retv);
				free(retv);
				return(temp);
			}
			// i++;
		// }
	}
	printf("bufferfinal: %s\n", buffer);
	return (retv);
}

int main()
{
	int fd = open("test.txt", 0);
	printf("rv1: %s\n", get_next_line(fd));
	printf("rv2: %s\n", get_next_line(fd));
	return (0);
}