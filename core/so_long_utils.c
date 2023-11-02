/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:08:57 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlenmap(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

int	ft_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_check_coin(char **map, t_slg *s)
{
	int	i;
	int	j;

	s->i = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				s->i++;
			j++;
		}
		i++;
	}
}

void	player_pos(t_slg *s)
{
	s->x = 0;
	while (s->map[s->x])
	{
		s->y = 0;
		while (s->map[s->x][s->y])
		{
			if (s->map[s->x][s->y] == 'P')
				return ;
			s->y++;
		}
		s->x++;
	}
	return ;
}

void	exit_position(t_slg *s)
{
	s->x = 0;
	while (s->map[s->x])
	{
		s->y = 0;
		while (s->map[s->x][s->y])
		{
			if (s->map[s->x][s->y] == 'E')
				return ;
			s->y++;
		}
		s->x++;
	}
}
