/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:02:36 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 19:09:10 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	measure_columns(t_map *map)
{
	char	*ptr_to_newline;
	int		line_size;

	ptr_to_newline = ft_strchr(map->string, '\n');
	if (ptr_to_newline)
		line_size = ptr_to_newline - map->string;
	else
		line_size = 0;
	return (line_size);
}

int	measure_lines(t_map *map)
{
	char	**map_lines;
	int		array_length;

	map_lines = ft_split(map->string, '\n');
	array_length = array_len(map_lines);
	free_map_array(array_length, map_lines, map, 0);
	return (array_length);
}
