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

/*to read a line*/
char	*read_line(char *str, int fd)
{
	char	*reader;
	int		nb_bytes_read;

	nb_bytes_read = 1;
	if (!str)
		return (0);
	// peut etre utiliser calloc pour avoir une ligne en moins
	reader = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reader)
		return (0);
	while (nb_bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		nb_bytes_read = read(fd, reader, BUFFER_SIZE);
		if (nb_bytes_read == -1)
		{
			free(reader);
			return (0);
		}
		reader[nb_bytes_read] = '\0';
		str = ft_strjoin(str, reader);
	}
	free (reader);
	return (str);
}

/*on veut copier la ligne dans la memoire*/

char	*store_line(char *str)
{
	int		index;
	char	*s;

	index = 0;
	if (!str)
		return (0);
	while (str && str[index] != '\n')
		index++;
	// on met 2 pour avoir le \0 et le \n
	s = malloc(sizeof(char) * (index + 2));
	if (!s)
		return (0);
	index = 0;
	while (str)
	{
		s[index] = str[index];
		index++;
	}
	//tu me copie la nouvelle ligne en plus et ensuite tu termines la str
	if (str[index] == '\n')
	{
		s[index] = str[index];
		index++;
	}
	s[index] = '\0';
	return (s);
}

/*on veut free la memoire tout en gardant en memoire les dernieres lignes*/
char	*free_selection(char *str)
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
		return (0);
	}
	backup = malloc (sizeof(char) *(ft_strlen(str) - index + 1));
    if (!backup)
        return(0);
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

	if (BUFFER_SIZE <= 0 || fd < 0 || read (fd, &line_read, 0) < 0)
		return (0);
	str = read_line(str, fd);
	if (!str)
		return (0);
	line_read = store_line(str);
	str = free_selection(str);
	if (line_read[0] == '\0')
	{
		free (str);
		free (line_read);
		return (0);
	}
	return (line_read);
}
