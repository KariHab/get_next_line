/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:09 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:09 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_the_line(char *str)
{
	int index;
	char *line;

	index = 0;
	while (str[index] != '\n' && str[index])
		index++;
	if (str[0] == '\0')
		return (NULL);
	line = ft_calloc((index + 2), sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	return (line);
}

char *ft_get_the_next(char *str)
{
	int index;
	int index_2;
	char *next;

	index = 0;
	while (str[index] != '\n' && str[index])
		index++;
	if (str[index] == '\0')
	{
		free(str);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(str) - index + 1), sizeof(char));
	if (!next)
	{
		free(next);
		return (NULL);
	}
	index_2 = 0;
	index++;
	while (str[index])
		next[index_2++] = str[index++];
	free(str);
	return (next);
}

int ft_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char *ft_read(int fd, char *buf, char *tmp, char *str)
{
	int nb_bytes;

	nb_bytes = 1;
	while (nb_bytes != 0)
	{
		nb_bytes = read(fd, buf, BUFFER_SIZE);
		if (nb_bytes == 0)
			break;
		if (nb_bytes == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[nb_bytes] = '\0';
		tmp = str;
		if (!tmp)
			tmp = ft_calloc(1, sizeof(char));
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_newline(str) == 1)
			break;
	}
	free(buf);
	return (str);
}

char *get_next_line(int fd)
{
	static char *str;
	char *buf;
	char *line;
	char *tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_get_the_line(str);
	str = ft_get_the_next(str);
	return (line);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
