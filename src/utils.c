/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:13:11 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 18:13:31 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_map *map, char *message)
{
	printf("%s", message);
	free(map->string);
	exit(1);
}

int	array_len(char **array)
{
	int		array_length;

	array_length = 0;
	while (array[array_length])
		array_length++;
	return (array_length);
}

void	free_map_array(int array_length, char **array, t_map *map, int error)
{
	while (--array_length >= 0)
		free(array[array_length]);
	free(array);
	if (error == NOT_RECTANGULAR)
		exit_program(map, "Error\nThe map must be rectangular\n");
	if (error == INVALID_WALL)
		exit_program(map, "Error\nThe map must be surrounded by walls.\n");
}