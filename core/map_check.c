/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:01:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:05 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_line(char **map, t_error *error)
{
	int	length;

	error->x = 0;
	error->nb_line = 0;
	length = ft_strlen(map[error->x]);
	while (map[error->x])
	{
		if (ft_strlen(map[error->x]) != length)
			return (0);
		error->nb_line++;
		error->x++;
	}
	return (1);
}

static	int	check_border(char **map, t_error *error)
{
	int	lenght;

	error->x = 0;
	lenght = ft_strlen(map[error->x]);
	error->y = 1;
	while (map[0][error->y] != '\n')
	{
		if (map[0][error->y] != '1')
			return (0);
		error->y++;
	}
	while (map[error->x])
	{
		if (map[error->x][0] != '1' || map[error->x][lenght - 2] != '1')
			return (0);
		error->x++;
	}
	error->y = 1;
	while (map[error->nb_line - 1][error->y] != '\n')
	{
		if (map[error->nb_line - 1][error->y] != '1')
			return (0);
		error->y++;
	}
	return (1);
}

static int	check_badchar(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_ressource(char **map, t_error *error)
{
	char	*charset;

	error->player = 0;
	error->coin = 0;
	error->exit = 0;
	charset = "10CPE\n";
	error->x = 0;
	while (map[error->x])
	{
		error->y = 0;
		while (map[error->x][error->y])
		{
			if (check_badchar(map[error->x][error->y], charset) == 0)
				return (0);
			if (map[error->x][error->y] == 'C')
				error->coin++;
			if (map[error->x][error->y] == 'P')
				error->player++;
			if (map[error->x][error->y] == 'E')
				error->exit++;
			error->y++;
		}
		error->x++;
	}
	return (1);
}

int	map_check(char **map)
{
	t_error	error;

	if (check_line(map, &error) == 0)
	{
		ft_printf("%s", "Error\nLength of uneven lines\n");
		return (0);
	}
	if (check_border(map, &error) == 0)
	{
		ft_printf("%s", "Error\nThe edges are not properly firm\n");
		return (0);
	}
	if (check_ressource(map, &error) == 0 || error.exit != 1 \
	|| error.player != 1 || error.coin < 1)
	{
		ft_printf("%s", "Error\nBad elements or not enough/too many elements\n");
		return (0);
	}
	if ((map_solver(map)) == 0)
	{
		ft_printf("%s", "Error\nUnfinishable Map\n");
		return (0);
	}
	return (1);
}
