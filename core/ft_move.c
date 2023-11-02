/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:41:24 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:37:35 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_step(int keycode, t_slg *s)
{
	if (keycode == 13 && s->map[s->x - 1][s->y] != '1')
		return (1);
	else if (keycode == 1 && s->map[s->x + 1][s->y] != '1')
		return (1);
	else if (keycode == 0 && s->map[s->x][s->y - 1] != '1')
		return (1);
	else if (keycode == 2 && s->map[s->x][s->y + 1] != '1')
		return (1);
	return (0);
}

void	replace_char(t_slg *s)
{
	int	tmp_x;
	int	tmp_y;

	if (s->map[s->x][s->y] == 'P')
		s->map[s->x][s->y] = '0';
	else if (s->map[s->x][s->y] == 'C')
	{
		s->map[s->x][s->y] = '0';
		s->i--;
		if (s->i == 0)
		{
			tmp_x = s->x;
			tmp_y = s->y;
			exit_position(s);
			what_texture(s->map[s->x][s->y], s->x, s->y, s);
			s->x = tmp_x;
			s->y = tmp_y;
		}
		what_texture(s->map[s->x][s->y], s->x, s->y, s);
	}
}

void	player_move(int keycode, t_slg *s)
{
	replace_char(s);
	if (keycode == 13 && s->map[s->x - 1][s->y] != '1')
		what_texture(s->map[s->x][s->y], s->x--, s->y, s);
	else if (keycode == 1 && s->map[s->x + 1][s->y] != '1')
		what_texture(s->map[s->x][s->y], s->x++, s->y, s);
	else if (keycode == 0 && s->map[s->x][s->y - 1] != '1')
		what_texture(s->map[s->x][s->y], s->x, s->y--, s);
	else if (keycode == 2 && s->map[s->x][s->y + 1] != '1')
		what_texture(s->map[s->x][s->y], s->x, s->y++, s);
	replace_char(s);
	s->img = mlx_xpm_file_to_image(s->mlx, "img/alien_r.xpm", &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, (s->y * 64), \
	(s->x * 64));
}

int	ft_move(int keycode, t_slg *s)
{
	static int	init;
	static int	nb_move;

	if (init == 0)
	{
		player_pos(s);
		init++;
	}
	if (ft_check_step(keycode, s) == 1)
	{
		nb_move++;
		ft_printf("Number of step : %d\n", nb_move);
	}
	player_move(keycode, s);
	if (keycode == 53 || (s->i == 0 && s->map[s->x][s->y] == 'E'))
	{
		mlx_destroy_image(s->mlx, s->img);
		exit(0);
	}
	return (0);
}
