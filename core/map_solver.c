/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:13:54 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:11 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_finishable(t_error *error)
{
	int	x;
	int	y;

	x = 0;
	while (error->map[x])
	{
		y = 0;
		while (error->map[x][y])
		{
			if (error->map[x][y] == 'C' || error->map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int	solver_dfs(t_error *error, int x, int y)
{
	if (error->map[x][y] != '1' || error->map[x][y] != '*')
	{
		error->map[x][y] = '*';
		if (error->map[x][y + 1] != '1' && error->map[x][y + 1] != '*')
			solver_dfs(error, x, y + 1);
		if (error->map[x][y - 1] != '1' && error->map[x][y - 1] != '*')
			solver_dfs(error, x, y - 1);
		if (error->map[x + 1][y] != '1' && error->map[x + 1][y] != '*')
			solver_dfs(error, x + 1, y);
		if (error->map[x - 1][y] != '1' && error->map[x - 1][y] != '*')
			solver_dfs(error, x - 1, y);
	}
	return (1);
}

static void	player_position(t_error *error)
{
	error->x = 0;
	while (error->map[error->x])
	{
		error->y = 0;
		while (error->map[error->x][error->y])
		{
			if (error->map[error->x][error->y] == 'P')
				return ;
			error->y++;
		}
		error->x++;
	}
	return ;
}

int	map_solver(char **map)
{
	t_error	error;
	int		i;

	i = 0;
	error.map = map;
	player_position(&error);
	solver_dfs(&error, error.x, error.y);
	if (is_finishable(&error) == 0)
		return (0);
	return (1);
}
