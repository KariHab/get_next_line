/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:19 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:19 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_before(char *str);
char *ft_after(char *str);
int ft_newline(char *str);
char *ft_read(int fd, char *buf, char *tmp, char *str);
void *ft_calloc(size_t count, size_t size);
void ft_bzero(void *s, size_t n);

#endif
