/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:39 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/07/30 18:32:02 by cyu-xian         ###   ########.fr       */
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
	char	book[BUFFER_SIZE + 1];
	char	*temp;
	int		num;

	if (fd < 0)
		return (0);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	// printf("buffernew: %s\n", buffer);
	retv = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	num = 1;
	while (num > 0)
	{
		num = read(fd, book, BUFFER_SIZE);
		book[num] = '\0';
		printf("book: %s\n", book);
		i = 0;
		if (ft_strchr(book, '\n') == 0 && ft_strchr(buffer, '\n') == 0)
		{
			// temp = buffer;
			buffer = ft_strjoin(buffer, book);
			// free(temp);
			retv = buffer;
		}
		else
		{
			i = new_line_finder(book);
			retv = trimmer(i, buffer, book); //find \n; substr it; return it
			buffer = ft_strdup(book + 1 + i);
			printf("%s\n", buffer);
			return(retv);
		}
	}
	// if (num == 0)
	// 	free(buffer);
	return (retv);
}

int main()
{
	int fd = open("test.txt", 0);
	char *rv1 = get_next_line(fd);
	char *rv2 = get_next_line(fd);
	char *rv3 = get_next_line(fd);
	// char *rv4 = get_next_line(fd);

	printf("rv1: %s\n", rv1);	
	printf("rv2: %s\n", rv2);
	printf("rv3: %s\n", rv3);
	// printf("rv4: %s\n", rv4);
	free(rv1);
	free(rv2);
	free(rv3);
	// free(rv4);
	// system("leaks a.out");
	return (0);
}