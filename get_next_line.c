/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:30:50 by abdel-ma          #+#    #+#             */
/*   Updated: 2023/12/30 02:04:37 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    
}
int main()
{
    int fd;
    char buf[300];
    int char_read;

    fd = open("mars.txt", O_RDONLY);
    while ((char_read = read(fd, buf, 10)))
    {
        buf[char_read] = '\0';
        printf("buf-> %s", buf);
    }
}