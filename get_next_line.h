/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:22:33 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/04 17:16:05 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_is_set(char *s);
char	*ft_strdup(char *src);
char	*ft_substr(char *str, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
int		get_next_line(int fd, char **line);
int		ft_return_value(char **str, int fd, char *buff, char **line);

#endif
