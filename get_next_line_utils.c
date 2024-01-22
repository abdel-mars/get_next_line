/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:20:01 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/01/22 00:14:42 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(const char *str1, const char *str2)
{
    char *res;
    int i;
    int j;

	i = 0;
	j = 0;
    res = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    while (str1[i] != '\0')
        res[j++] = str1[i++];
    i = 0;
    while (str2[i] != '\0')
	{
		res[j++] = str2[i];
	}
    res[j] = '\0';
    return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start > len)
		size = len;
	else
	size = ft_strlen(s) - start;
		sub = (char *)malloc(sizeof(char ) * (size + 1));
	if (!sub)
		return (NULL);
	while (i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *str)
{
	size_t		len;
	size_t		i;
	char		*dup;

	len = ft_strlen(str);
	i = 0;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			cch;

	i = 0;
	cch = c;
	while (str[i])
	{
		if (str[i] == cch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
