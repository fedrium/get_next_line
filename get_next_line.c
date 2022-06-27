/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:39 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/06/27 15:38:10 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	int	i;
	static	char	*buffer;
	buffer = (char*)sizeof(char) * BUFFER_SIZE;

	while (buffer[i] != '\0')
	{
		read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (buffer[i] != '\n')
		{
			
		}
	}
}