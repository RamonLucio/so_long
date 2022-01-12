/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:08:27 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 19:08:26 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_xpm_to_image(t_map *map)
{
	map->tile.img = mlx_xpm_file_to_image(map->mlx, "assets/tile.xpm",
			&map->tile.width, &map->tile.height);
	map->wall.img = mlx_xpm_file_to_image(map->mlx, "assets/wall.xpm",
			&map->wall.width, &map->wall.height);
	map->coin.img = mlx_xpm_file_to_image(map->mlx, "assets/coin.xpm",
			&map->coin.width, &map->coin.height);
	map->exit.img = mlx_xpm_file_to_image(map->mlx, "assets/exit.xpm",
			&map->exit.width, &map->exit.height);
	map->player.img = mlx_xpm_file_to_image(map->mlx, "assets/player.xpm",
			&map->player.width, &map->player.height);
}

static void	put_image_to_window(t_map *map, int x, int y, int i)
{
	if (map->string[i] == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->tile.img, x, y);
	if (map->string[i] == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->wall.img, x, y);
	if (map->string[i] == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->coin.img, x, y);
	if (map->string[i] == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->exit.img, x, y);
	if (map->string[i] == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->player.img, x, y);
}

static void	destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx, map->tile.img);
	mlx_destroy_image(map->mlx, map->wall.img);
	mlx_destroy_image(map->mlx, map->coin.img);
	mlx_destroy_image(map->mlx, map->exit.img);
	mlx_destroy_image(map->mlx, map->player.img);
}

int	render_map(t_map *map)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	read_xpm_to_image(map);
	while (y < map->height)
	{
		while (x < map->width)
		{
			put_image_to_window(map, x, y, i);
			x += map->tile.width;
			i++;
		}
		x = 0;
		y += map->tile.height;
		i++;
	}
	destroy_image(map);
	return (0);
}
