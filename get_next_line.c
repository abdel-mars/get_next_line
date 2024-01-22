/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:30:50 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/01/22 02:29:10 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *set_line(char *line_buff)
{
    char *rest;
    ssize_t i;
    
    i = 0;
    while (line_buff[i] != '\n' && line_buff[i] != '\0')
        i++;
    if (line_buff[i] == '\0' || line_buff[1] == '\0')
        return (NULL);
    line_buff[i + 1] = '\0';
    rest = ft_strdup(line_buff + i + 1);
    if (*rest == '\0')
    {
        free(rest);
        rest = NULL;
    }
    return (rest);
    
}

static char *read_line(int fd, char *rest, char *buff)
{
    ssize_t read_buff;
    char *tmp;
    
    read_buff = 1;
    while(read_buff > 0)
    {
        read_buff = read(fd, buff, BUFFER_SIZE);
        if (read_buff == -1)
        {
            free(rest);
            return(NULL);
        }
        buff[read_buff] = '\0';
        if (!rest)
        {
            rest = ft_strdup("");
        }
        tmp = rest;
        rest  = ft_strjoin(tmp, buff);
        free (tmp);
        if (ft_strchr(buff, '\n'))
        break;
    }
    return (rest);
}

char *get_next_line(int fd)
{
    static char *rest;
    char *line;
    char *buff;

    buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
    if (!buff)
        return (NULL);
    else if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
    {
        free(rest);
        free(buff);
        rest = NULL;
        buff = NULL;
        return (NULL);
    }
    line = read_line(fd, rest, buff);
    free (buff);
    if (!line)
        return (NULL);
    rest = set_line(line);
    return (line);
}
