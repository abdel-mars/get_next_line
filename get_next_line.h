/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:39:29 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/01/23 00:25:05 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *str1, char const *str2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *str);
char    *ft_strchr(const char *str, int c);

#endif
