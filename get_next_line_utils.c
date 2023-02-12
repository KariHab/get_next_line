/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:14 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:14 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(const char *s1, const char *s2)
{
	char *newstr;
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (0);
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (0);
	else
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			newstr[i++] = s1[j++];
		}
		j = 0;
		while (s2[j])
		{
			newstr[i++] = s2[j++];
		}
		newstr[i] = '\0';
	}
	return (newstr);
}

size_t ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str && str[index])
	{
		index++;
	}
	return (index);
}

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void ft_bzero(void *s, size_t n)
{
	size_t i;

	if (!s)
		return;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}