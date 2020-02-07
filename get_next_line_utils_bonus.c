/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:33:00 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/05 03:17:56 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_is_set(char *s)
{
	int start;

	if (!s)
		return (0);
	start = 0;
	while (s[start])
	{
		if (s[start] == '\n')
			return (1);
		start++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	if (!(dest = (char*)malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = str[start + i];
	dest[i] = '\0';
	if (str && start != 0)
		free(str);
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	if (!(dest = ((char*)malloc(sizeof(char) * (ft_strlen(src) + 1)))))
		return (0);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int		ft_return_value(char **str, int fd, char *buff, char **line)
{
	int i;

	i = 0;
	if (str[fd][0] && ft_is_set(str[fd]))
	{
		while (str[fd][i] != '\n' && str[fd][i])
			i++;
		(*line) = i == 0 ? ft_strdup("") : ft_substr(str[fd], 0, i);
		str[fd] = ft_substr(str[fd], i + 1, BUFFER_SIZE);
		free(buff);
		return (1);
	}
	else if (str[fd][0] && !ft_is_set(str[fd]))
		*line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
	else
		(*line) = ft_strdup("");
	free(str[fd]);
	str[fd] = NULL;
	free(buff);
	return (0);
}
