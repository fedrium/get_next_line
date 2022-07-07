/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:59:43 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/07/07 18:05:04 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*trimmer(buffer, i, retv)
{
	char *temp;

	temp = ft_substr(buffer, 0, i);
	ft_strjoin(retv, temp);
	
}
