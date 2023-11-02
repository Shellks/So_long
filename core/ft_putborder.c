/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putborder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:30:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:37:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_put_down(char **map, t_slg *s, int length)
{
	char	*texture;
	int		i;

	texture = "img/down_left_wall.xpm";
	s->x = 0;
	s->y = ((ft_line(map) * 64) - 64);
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
	texture = "img/down_wall.xpm";
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	s->x += 64;
	i = 0;
	while (i < (length - 2))
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
		s->x += 64;
		i++;
	}
	texture = "img/down_right_wall.xpm";
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
}

static void	ft_put_side(char **map, t_slg *s, int length)
{
	char	*texture;

	texture = "img/left_wall.xpm";
	s->x = 0;
	s->y = 64;
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
	while (s->y < ((ft_line(map) * 64) - 64))
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
		s->y += 64;
	}
	texture = "img/right_wall.xpm";
	s->x = ((length - 1) * 64);
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
	s->y = 64;
	while (s->y < ((ft_line(map) * 64) - 64))
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
		s->y += 64;
	}
}

static void	ft_put_top(t_slg *s, int length)
{
	char	*texture;
	int		i;

	texture = "img/top_left_wall.xpm";
	s->x = 0;
	s->y = 0;
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
	texture = "img/top_wall.xpm";
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	i = 0;
	s->x += 64;
	while (i < (length - 2))
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
		s->x += 64;
		i++;
	}
	texture = "img/top_right_wall.xpm";
	s->img = mlx_xpm_file_to_image(s->mlx, texture, &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, s->x, s->y);
}

void	ft_putborder(char **map, t_slg *slg)
{
	int		length;

	slg->x = 0;
	length = ft_strlenmap(map[slg->x]);
	ft_put_top(slg, length);
	ft_put_side(map, slg, length);
	ft_put_down(map, slg, length);
}
