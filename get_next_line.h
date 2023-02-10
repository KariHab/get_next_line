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

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	    *get_next_line(int fd);
size_t	    ft_strlen(char *str);
char	    *ft_strchr(char *s, int c);
char	    *ft_strjoin(char *s1, char *s2);
char	*ft_update_file(char *str);
char	*ft_get_store_line(char *str);
char	*ft_read_save(char *str, int fd);
void        *ft_calloc(size_t count, size_t size);
void        ft_bzero(void *s, size_t n);

#endif
