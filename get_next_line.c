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

/*to read a file*/
char	*read_file(char *str, int fd)
{
	char	*reader;
	int		nb_bytes;
	char	*tmp;

	if (!str)
		str = ft_calloc(1, 1);
	reader = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!reader)
		return (0);
	nb_bytes = 1;
	while (nb_bytes > 0)
	{
		/*while it' s not eof - va lire la totalite de buffer_size du fichier si 42 va lire 42 char*/
		nb_bytes = read(fd, reader, BUFFER_SIZE);
		/*si erreur de la fonction read()*/
		if (nb_bytes == -1)
		{
			free(reader);
			return (0);
		}
		/*pour dire qu' on a la place pour tout ce qui doit etre lu + le \0 donc on le fini*/
		// reader[nb_bytes] = 0;
		/*on va join le str + la space de notre file lu. On va liberer la memoire du str et on va retourner notre bloc*/
		tmp = ft_strjoin(str, reader);
		free(str);
		return (tmp);
		/*quit if find \n*/
		if (ft_strchr(str, '\n'))
			break;
	}
	free (reader);
	return (str);
}

/*OK - on veut copier la ligne dans la memoire - take line for return*/
char	*store_line(char *str)
{
	int		index;
	char	*s;

	index = 0;
	/*if no line return 0*/
	if (!str)
		return (0);
		/*go to eol*/
	while (str[index] && str[index] != '\n')
		index++;
		/*malloc to eol*/
	s = ft_calloc((index + 2), sizeof(char));
	if (!s)
		return (0);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		s[index] = str[index];
		index++;
	}
	/*if eol is \0 or \n replace eol by \n*/
	if (str[index] && str[index] == '\n')
		s[index++] = '\n';
	return (s);
}

/*OK - on veut free la memoire tout en gardant en memoire les dernieres lignes- delete line find*/
char	*free_selection(char *str)
{
	int		index;
	int		index_2;
	char	*backup;

	index = 0;
	/*trouver size of first line*/
	while (str && str[index] != '\n')
		index++;
	/*si eol return 0*/
	if (!str[index])
	{
		free(str);
		return (0);
	}
	/*len of file - len of first line + 1 for \0*/
	backup = ft_calloc((ft_strlen(str) - index + 1), sizeof(char));
	if (!backup)
		return (0);
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

	if (BUFFER_SIZE <= 0 || fd < 0 || read (fd, 0, 0) < 0)
		return (0);
	str = read_file(str, fd);
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
