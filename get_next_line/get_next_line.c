/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:10:25 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/04 16:55:24 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	char	*keep;
	int		start;
	int		i;

	start = 0;
	i = 0;
	while (str[start] && str[start] != '\n')
		start++;
	if (!str[start])
		return (free(str), str = NULL, NULL);
	keep = ft_calloc(ft_strlen(str) - start + 1, sizeof(char));
	if (!keep)
		return (free(str), free(keep), str = NULL, keep = NULL, NULL);
	start++;
	while (str[start])
	{
		keep[i] = str[start];
		i++;
		start++;
	}
	return (free(str), str = NULL, keep);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str[i])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == 0)
		line = (char *)ft_calloc((len + 1), sizeof(char));
	else
		line = (char *)ft_calloc((len + 2), sizeof(char));
	if (!line)
		return (free(line), line = NULL, NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != 0)
		line[i] = '\n';
	return (line);
}

char	*ft_read_line(char *str, int fd)
{
	int		count;
	char	*buf;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free(str), str = NULL, NULL);
	count = 1;
	while (count > 0)
	{
		count = (int)read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (free(buf), buf = NULL, free(str), str = NULL, NULL);
		buf[count] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), buf = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(str), str = NULL, NULL);
	str = ft_read_line(str, fd);
	if (!str || str[0] == 0)
		return (free(str), str = NULL, NULL);
	line = ft_get_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_next_line(str);
	return (line);
}
