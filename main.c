/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/30 20:05:13 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(int argc, char *argv[])
{
	int	file_descriptor;

	if (argc != 2)
	{
		printf("Error\nThe program must have one argument!\n");
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

void	exit_program(char **map, char *message)
{
	printf("%s", message);
	free(*map);
	exit(1);
}

void	parse_characters(char **map)
{
	char	*map_ptr;
	int		collectible;
	int		exit;
	int		start;

	map_ptr = *map;
	collectible = 0;
	exit = 0;
	start = 0;
	while (*map_ptr)
	{
		if (*map_ptr != '0' && *map_ptr != '1' && *map_ptr != 'C'
			&& *map_ptr != 'E' && *map_ptr != 'P' && *map_ptr != '\n')
			exit_program(map, "Error\nMap contains forbidden character\n");
		if (*map_ptr == 'C')
			collectible++;
		if (*map_ptr == 'E')
			exit++;
		if (*map_ptr == 'P')
			start++;
		map_ptr++;
	}
	if (collectible == 0 || exit == 0 || start == 0)
		exit_program(map, "Error\nMap must have start, exit and collectible\n");
}

int	array_len(char **array)
{
	int		array_length;

	array_length = 0;
	while (array[array_length])
		array_length++;
	return (array_length);
}

int	check_top_and_bottom_wall(char **map_lines, int i, int j)
{
	while (map_lines[i][j])
	{
		if (map_lines[i][j++] != '1')
			return (INVALID_WALL);
	}
	return (VALID_WALL);
}

void	free_map_array(int array_length, char **array, char **map, int error)
{
	while (--array_length >= 0)
		free(array[array_length]);
	free(array);
	if (error == INVALID_WALL)
		exit_program(map, "Error\nThe map must be surrounded by walls.\n");
}

void	parse_walls(char **map)
{
	char	**map_lines;
	int		array_length;
	int		i;
	int		j;

	map_lines = ft_split(*map, '\n');
	array_length = array_len(map_lines);
	i = 0;
	j = 0;
	if (check_top_and_bottom_wall(map_lines, i, j))
		free_map_array(array_length, map_lines, map, INVALID_WALL);
	j = ft_strlen(map_lines[0]) - 1;
	while (++i < array_length - 1)
	{
		if (map_lines[i][0] != '1')
			free_map_array(array_length, map_lines, map, INVALID_WALL);
		if (map_lines[i][j] != '1')
			free_map_array(array_length, map_lines, map, INVALID_WALL);
	}
	if (check_top_and_bottom_wall(map_lines, i, 0))
		free_map_array(array_length, map_lines, map, INVALID_WALL);
	free_map_array(array_length, map_lines, map, VALID_WALL);
}

int	handle_no_event(t_ptr *ptr_to)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr_to->tile.img = mlx_xpm_file_to_image(ptr_to->mlx, "assets/tile.xpm",
			&ptr_to->tile.width, &ptr_to->tile.height);
	while (j < 512)
	{
		while (i < 512)
		{
			mlx_put_image_to_window(
				ptr_to->mlx, ptr_to->win, ptr_to->tile.img, i, j);
			i += 16;
		}
		i = 0;
		j += 16;
	}
	mlx_destroy_image(ptr_to->mlx, ptr_to->tile.img);
	return (0);
}

int	escape_window(int keycode, t_ptr *ptr_to)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(ptr_to->mlx, ptr_to->win);
		mlx_destroy_display(ptr_to->mlx);
		free(ptr_to->mlx);
		exit(0);
	}
	return (0);
}

int	close_window(t_ptr *ptr_to)
{
	mlx_destroy_window(ptr_to->mlx, ptr_to->win);
	mlx_destroy_display(ptr_to->mlx);
	free(ptr_to->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_ptr	ptr_to;
	int		file_descriptor;
	char	*map;

	file_descriptor = open_map(argc, argv);
	map = read_map(file_descriptor);
	parse_characters(&map);
	parse_walls(&map);
	free(map);
	ptr_to.mlx = mlx_init();
	if (ptr_to.mlx == NULL)
		return (1);
	ptr_to.win = mlx_new_window(ptr_to.mlx, 512, 512, "./so_long");
	if (ptr_to.win == NULL)
	{
		free(ptr_to.win);
		return (1);
	}
	mlx_loop_hook(ptr_to.mlx, handle_no_event, &ptr_to);
	mlx_hook(ptr_to.win, KeyRelease, KeyReleaseMask, &escape_window, &ptr_to);
	mlx_hook(ptr_to.win, DestroyNotify, StructureNotifyMask, &close_window,
		&ptr_to);
	mlx_loop(ptr_to.mlx);
	return (0);
}
