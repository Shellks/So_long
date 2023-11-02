/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:12 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:39:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/printf.h"

typedef struct s_slg
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		i;
	int		x;
	int		y;
	int		h;
	int		w;
}	t_slg;

typedef struct s_error
{
	char	**map;
	int		nb_line;
	int		coin;
	int		player;
	int		exit;
	int		x;
	int		y;
}	t_error;

void	so_long(char **map);
int		ft_line(char **map);
void	ft_free(char **map);
void	player_pos(t_slg *s);
int		map_check(char **map);
int		map_solver(char **map);
int		ft_strlenmap(char *str);
void	exit_position(t_slg *s);
char	**map_parsing(char **av);
int		ft_move(int keycode, t_slg *s);
void	ft_putcenter(char **map, t_slg *s);
void	ft_check_coin(char **map, t_slg *s);
void	ft_putborder(char **map, t_slg *slg);
void	what_texture(char c, int x, int y, t_slg *s);

#endif
