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

/*to save memory according to buffer*/
char	*ft_read_save(char *str, int fd)
{
	char	*buffer;
	int		nb_bytes;

	/*on veut pouvoir garder de la memoire pour tout le buffer_size*/
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	nb_bytes = 1;
	/**/
	while (!ft_strchr(str, '\n') && nb_bytes !=0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes <= 0)
		{
			free(buffer);
			return (NULL);
		}
		/*on va ajouter le buffer saved*/
		str = ft_strjoin(str, buffer);
	} 
	free (buffer);
	return (str);
}

/*get the line and save it*/
char	*ft_get_store_line(char *str)
{
	int		index;
	char	*s;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	s = ft_calloc((index + 2), sizeof(char));
	if (!s)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		s[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		s[index] = str[index];
		index++;
	}
	s[index] = '\0';
	return (s);
}

/*update the file without the line read*/
char	*ft_update_file(char *str)
{
	int		index;
	int		index_2;
	char	*backup;

	index = 0;
	while (str && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	backup = ft_calloc((ft_strlen(str) - index + 1), sizeof(char));
	if (!backup)
		return (NULL);
	index++;
	index_2 = 0;
	while (str[index])
	{
		backup[index_2++] = str[index++];
	}
	backup[index_2] = '\0';
	free (str);
	return (backup);
}

/*read a file line after line*/

char	*get_next_line(int fd)
{
	char		*line_read;
	static char	*str;

	if (BUFFER_SIZE < 1 || fd < 0 || read (fd, 0, 0) < 0)
		return (NULL);
	str = ft_read_save(str, fd);
	if (!str)
		return (NULL);
	line_read = ft_get_store_line(str);
	str = ft_update_file(str);
	return (line_read);
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
