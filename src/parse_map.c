/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:53:13 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 23:25:42 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_characters(t_map *map)
{
	char	*map_ptr;

	map_ptr = map->string;
	map->collectibles = 0;
	map->exit_char = 0;
	map->start = 0;
	while (*map_ptr)
	{
		if (*map_ptr != '0' && *map_ptr != '1' && *map_ptr != 'C'
			&& *map_ptr != 'E' && *map_ptr != 'P' && *map_ptr != '\n')
			exit_program(map, "Error\nMap contains invalid character\n");
		if (*map_ptr == 'C')
			map->collectibles++;
		if (*map_ptr == 'E')
			map->exit_char++;
		if (*map_ptr == 'P')
			map->start++;
		map_ptr++;
	}
	if (map->collectibles == 0 || map->exit_char == 0 || map->start == 0)
		exit_program(map, "Error\nMap must have C, E, P characters\n");
	if (map->exit_char != 1 || map->start != 1)
		exit_program(map, "Error\nMap must have one player and one exit\n");
}

static void	is_rectangular(t_map *map, char **map_array)
{
	int		array_length;
	int		i;
	int		line_length;
	int		temp;

	array_length = array_len(map_array);
	i = 0;
	line_length = ft_strlen(map_array[i]);
	while (++i < array_length)
	{
		temp = ft_strlen(map_array[i]);
		if (line_length != temp)
			free_map_array(array_length, map_array, map, NOT_RECTANGULAR);
	}
}

static int	check_top_and_bottom_wall(char **map_array, int i, int j)
{
	while (map_array[i][j])
	{
		if (map_array[i][j++] != '1')
			return (INVALID_WALL);
	}
	return (VALID_MAP);
}

static void	parse_walls(t_map *map, char **map_array)
{
	int		array_length;
	int		i;
	int		j;

	array_length = array_len(map_array);
	i = 0;
	j = 0;
	if (check_top_and_bottom_wall(map_array, i, j))
		free_map_array(array_length, map_array, map, INVALID_WALL);
	j = ft_strlen(map_array[0]) - 1;
	while (++i < array_length - 1)
	{
		if (map_array[i][0] != '1')
			free_map_array(array_length, map_array, map, INVALID_WALL);
		if (map_array[i][j] != '1')
			free_map_array(array_length, map_array, map, INVALID_WALL);
	}
	if (check_top_and_bottom_wall(map_array, i, 0))
		free_map_array(array_length, map_array, map, INVALID_WALL);
	free_map_array(array_length, map_array, map, VALID_MAP);
}

void	parse_map(t_map *map)
{
	char	**map_array;

	parse_characters(map);
	map_array = ft_split(map->string, '\n');
	is_rectangular(map, map_array);
	parse_walls(map, map_array);
}
