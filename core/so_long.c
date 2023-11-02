/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:12:06 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:18 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	so_long(char **map)
{
	t_slg	slg;
	int		lo;
	int		la;

	slg.x = 0;
	la = ft_strlenmap(map[slg.x]);
	lo = ft_line(map);
	slg.map = map;
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, (la * 64), (lo * 64), "so_long");
	ft_putborder(map, &slg);
	ft_putcenter(map, &slg);
	mlx_hook(slg.mlx_win, 2, 0, ft_move, &slg);
	mlx_hook(slg.mlx_win, 17, 0, ft_close, &slg);
	mlx_loop(slg.mlx);
}
