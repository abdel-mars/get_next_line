/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:41:05 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/01/27 03:48:43 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*set_line(char *line_buff)
{
	char		*rest;
	ssize_t		i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == '\0' || line_buff[1] == '\0')
		return (NULL);
	rest = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line_buff[i + 1] = '\0';
	return (rest);
}

static char	*read_line(int fd, char *rest, char *buff)
{
	ssize_t	read_buff;
	char	*tmp;

	read_buff = 1;
	while (read_buff > 0)
	{
		read_buff = read(fd, buff, BUFFER_SIZE);
		if (read_buff == -1)
		{
			free(rest);
			return (NULL);
		}
		else if (read_buff == '\0')
			break ;
		buff[read_buff] = '\0';
		if (!rest)
			rest = ft_strdup("");
		tmp = rest;
		rest = ft_strjoin(tmp, buff);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest[fd]);
		free(buff);
		rest[fd] = NULL;
		buff = NULL;
		return (NULL);
	}
	line = read_line(fd, rest[fd], buff);
	free (buff);
	buff = NULL;
	if (!line)
		return (NULL);
	rest[fd] = set_line(line);
	return (line);
}
