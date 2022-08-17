/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:39 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/08/12 13:55:08 by cyu-xian         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	int	i;
	static	char	*buffer;
	char	*retv;
	char	book[BUFFER_SIZE + 1];
	char	*temp;
	int		num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	// retv = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	retv = NULL;
	num = read(fd, book, BUFFER_SIZE);
	i = 0;
	while (num > 0 || i != 0)
	{	
		book[num] = '\0';
		i = 0;
		temp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strjoin(temp, book);
		free(temp);
		if (ft_strchr(book, '\n') == 0 && ft_strchr(buffer, '\n') == 0)
		{
			free(retv);
			retv = ft_strdup(buffer);
		}
		else
		{
			i = new_line_finder(buffer);
			free(retv);
			retv = ft_substr(buffer, 0, i + 1); //find \n; substr it; return it
			temp = ft_strdup(buffer);
			free(buffer);
			buffer = ft_strdup(temp + 1 + i);
			free(temp);
			temp = ft_strdup(retv);
			free(retv);
			return(temp);
		}
		num = read(fd, book, BUFFER_SIZE);
	}
	if (!buffer && num == 0)
	{
		// free(buffer);
		// buffer = NULL;
		return (NULL);
	}
	return (retv);
}

int main()
{
	int fd = open("test.txt", 0);
	int	i;

	i = 5;

	while (1)
	{
		char *rv1 = get_next_line(fd);
		if (rv1 == NULL)
			break;
		printf("rv1: %s\n", rv1);	
		free(rv1);
	}
	// system("leaks a.out");
	return (0);
}