/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:39 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/06/29 14:26:34 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	int	i;
	static	char	*buffer;
	char	*retv;
	buffer = (char*)sizeof(char) * BUFFER_SIZE;

	while (buffer[i] != '\0')
	{
		read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (buffer[i] <= BUFFER_SIZE)
		{
			if (i == BUFFER_SIZE || buffer[i] != '\n')
				ft_strjoin(retv, buffer);
			if (buffer[i] == '\n')
			{
				trimmer(buffer, i, retv);
				return (retv);
			}
			i++;
		}
		return (buffer);
	}
	return (0);
}