/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:12:19 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 18:35:31 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	escape_window(int keycode, t_map *map)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(map->mlx, map->window);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free(map->string);
		exit(0);
	}
	return (0);
}

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map->string);
	exit(0);
	return (0);
}

void	receive_events(t_map *map)
{
	mlx_loop_hook(map->mlx, render_map, map);
	mlx_hook(map->window, KeyPress, KeyPressMask, move_player, map);
	mlx_hook(map->window, KeyRelease, KeyReleaseMask, escape_window, map);
	mlx_hook(map->window, DestroyNotify, StructureNotifyMask, close_window,
		map);
	mlx_loop(map->mlx);
}