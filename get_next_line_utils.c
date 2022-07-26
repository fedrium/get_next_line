/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:59:43 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/07/23 17:51:49 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*str;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	k = -1;
	l = 0;
	str = (char *)malloc (i + j + 1);
	if (str == NULL)
		return (NULL);
	while (i > ++k)
		str[k] = s1[k];
	while (j > l)
	{
		str[k] = s2[l];
		k++;
		l++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		k;
	char	*str;

	i = ft_strlen((char *)s1);
	k = 0;
	str = (char *)malloc (i + 1);
	if (str == NULL)
		return (NULL);
	while (s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	str[k] = '\0';
	return ((char *)&str[0]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	else if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc (len + 1);
	if (str == NULL)
		return (NULL);
	while (len > i && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int chr)
{
	int		i;
	char	c;
	char	*s;

	i = 0;
	c = chr;
	s = (char *)str;
	if (chr == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (chr == '\0')
		{
			if (s[i + 1] == '\0')
				return (&s[i + 1]);
		}
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*trimmer(char *retv, int i, char *book, char *buffer) //modify to work with strchr
{
	char *temp;

	retv = ft_strjoin(buffer, retv);
	temp = ft_substr(book, 0, i + 1);
	retv = ft_strjoin(retv, temp);
	return (retv);
}
