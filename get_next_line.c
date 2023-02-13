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

char	*ft_before(char *str)
{
	int		index;
	char	*ptr;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index] != '\n' && str[index])
		index++;
	if (str[0] == '\0')
	{
		return (NULL);
	}
	ptr = ft_calloc((index + 2), sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
	{
		ptr[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		ptr[index++] = '\n';
	return (ptr);
}

char	*ft_after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = ft_calloc((i - j), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	free(str);
	return (ptr);
}

int	ft_newline(char *str)
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

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	int	nb_bytes;

	nb_bytes = 1;
	while (nb_bytes != 0)
	{
		nb_bytes = read(fd, buf, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nb_bytes] = '\0';
		tmp = str;
		if (!tmp)
			tmp = ft_calloc(1, sizeof(char));
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_newline(str) == 1)
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
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
// 	return (0);
// }
