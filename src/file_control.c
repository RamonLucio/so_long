/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:41:45 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/12 18:52:28 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(int argc, char *argv[])
{
	int	file_descriptor;

	if (argc != 2)
	{
		printf("Error\nThe program must have one argument\n");
		exit(1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("Error\n");
		exit(1);
	}
	return (file_descriptor);
}

char	*read_map(int file_descriptor)
{
	char	*map;
	int		lines_read;
	char	*line;
	char	*temp;

	map = ft_strdup("");
	lines_read = 0;
	while (++lines_read)
	{
		line = get_next_line(file_descriptor);
		if (line == NULL)
			break ;
		temp = ft_strjoin(map, line);
		free(map);
		map = ft_strdup(temp);
		free(temp);
		free(line);
	}
	return (map);
}