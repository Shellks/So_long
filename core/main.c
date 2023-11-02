/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:06:58 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/23 18:38:03 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

int	main(int ac, char **av)
{
	char	**map;
	int		len;

	if (ac != 2)
	{
		ft_printf("%s", "Error\nnot enough or too many arguments\n");
		return (0);
	}
	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'b' \
	|| av[1][len - 2] != 'e' || av[1][len - 1] != 'r')
	{
		ft_printf("%s", "Error\nThe file should end with the .ber extension\n");
		return (0);
	}
	map = map_parsing(av);
	if (!map)
		return (0);
	if ((map_check(map)) == 0)
		return (ft_free(map), 0);
	ft_free(map);
	map = map_parsing(av);
	so_long(map);
	ft_free(map);
	return (1);
}
