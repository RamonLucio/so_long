/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 18:16:33 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int		file_descriptor;
	t_map	map;

	file_descriptor = open_map(argc, argv);
	map.string = read_map(file_descriptor);
	parse_map(&map);
	map.mlx = mlx_init();
	if (map.mlx == NULL)
		return (1);
	map.width = measure_columns(&map) * SPRITE_SIZE;
	map.height = measure_lines(&map) * SPRITE_SIZE;
	map.window = mlx_new_window(map.mlx, map.width, map.height, argv[0]);
	if (map.window == NULL)
	{
		free(map.window);
		return (1);
	}
	map.movements = 0;
	receive_events(&map);
	free(map.string);
	return (0);
}
