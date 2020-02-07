/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:21:22 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/05 02:08:24 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strcat(char *dest, char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return ((char*)dest);
}

static char		*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		len;

	if (!s1)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	dest[len] = '\0';
	free(s1);
	return (dest);
}

static int		ft_checkerror(int fd, char **str, char **line, char *buff)
{
	if (fd < 0 || fd > OPEN_MAX || !line || read(fd, buff, 0) != 0)
	{
		free(buff);
		return (-1);
	}
	if (!str[fd])
	{
		if (!(str[fd] = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

static char		*ft_read(char *str, int fd, char *buff)
{
	long int	ret;

	if (ft_is_set(str))
		return (str);
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_is_set(str) == 1)
			return (str);
	}
	return (str);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char		*buff;

	if (BUFFER_SIZE < 1 || !(buff = (char*)malloc(sizeof(char) *
	(BUFFER_SIZE + 1))) || (ft_checkerror(fd, str, line, buff) == -1))
		return (-1);
	str[fd] = ft_read(str[fd], fd, buff);
	i = ft_return_value(str, fd, buff, line);
	return (i);
}
