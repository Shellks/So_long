/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:17:47 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:37:59 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	what_texture(char c, int x, int y, t_slg *s)
{
	if (c == '1')
		s->img = mlx_xpm_file_to_image(s->mlx, "img/light_2.xpm", &s->w, &s->h);
	else
		s->img = mlx_xpm_file_to_image(s->mlx, "img/floor1.xpm", &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, (y * 64), (x * 64));
	if (c == 'E' && s->i != 0)
		s->img = mlx_xpm_file_to_image(s->mlx, "img/portalc.xpm", &s->w, &s->h);
	else if (c == 'E' && s->i == 0)
		s->img = mlx_xpm_file_to_image(s->mlx, "img/portalo.xpm", &s->w, &s->h);
	else if (c == 'C')
		s->img = mlx_xpm_file_to_image(s->mlx, "img/human.xpm", &s->w, &s->h);
	else if (c == 'P')
		s->img = mlx_xpm_file_to_image(s->mlx, "img/alien_r.xpm", &s->w, &s->h);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, (y * 64), (x * 64));
}

void	ft_putcenter(char **map, t_slg *s)
{
	int	length;
	int	nb_line;

	s->x = 0;
	ft_check_coin(map, s);
	nb_line = ft_line(map);
	length = (ft_strlenmap(map[s->x]) - 1);
	s->x = 1;
	while (map[s->x] && s->x < (nb_line - 1))
	{
		s->y = 1;
		while (map[s->x][s->y] && s->y < length)
		{
			what_texture(map[s->x][s->y], s->x, s->y, s);
			s->y++;
		}
		s->x++;
	}
}
