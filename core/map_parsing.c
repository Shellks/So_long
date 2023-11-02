/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:39:47 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:08 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**parsing(char **av, int nb_line)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open((av[1]), O_RDONLY);
	map = malloc(sizeof(char *) * nb_line + 1);
	if (!map)
		return (NULL);
	while (i < nb_line + 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

static int	line_count(char **av)
{
	char	*map;
	int		count;
	int		fd;

	count = 0;
	fd = open((av[1]), O_RDONLY);
	map = get_next_line(fd);
	if (map)
		count++;
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		if (map)
			count++;
	}
	close(fd);
	return (free(map), count);
}

char	**map_parsing(char **av)
{
	char	**map;
	int		nb_line;
	int		fd;

	fd = open((av[1]), O_RDONLY);
	close(fd);
	if (fd < 0)
	{
		ft_printf("Error\nThe file does not exist\n");
		return (NULL);
	}
	nb_line = line_count(av);
	map = parsing(av, nb_line);
	return (map);
}
