/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/11 18:40:36 by rlucio-l         ###   ########.fr       */
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

void	exit_program(t_map *map, char *message)
{
	printf("%s", message);
	free(map->string);
	exit(1);
}

void	parse_characters(t_map *map)
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

void	is_rectangular(t_map *map, char **map_array)
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

int	check_top_and_bottom_wall(char **map_array, int i, int j)
{
	while (map_array[i][j])
	{
		if (map_array[i][j++] != '1')
			return (INVALID_WALL);
	}
	return (VALID_MAP);
}

void	parse_walls(t_map *map, char **map_array)
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

void	read_xpm_to_image(t_map *map)
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

void	put_image_to_window(t_map *map, int x, int y, int i)
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

void	destroy_image(t_map *map)
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

int	escape_window(int keycode, t_map *map)
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

void	move_up(t_map *map)
{
	char	*player;
	char	*char_above;

	player = ft_strchr(map->string, 'P');
	char_above = player - (map->width / SPRITE_SIZE) - 1;
	if (*char_above == 'C' || *char_above == '0')
	{
		*char_above = 'P';
		*player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*char_above == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

void	move_left(t_map *map)
{
	char	*player;

	player = ft_strchr(map->string, 'P');
	player--;
	if (*player == 'C' || *player == '0')
	{
		*player = 'P';
		*++player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*player == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

void	move_down(t_map *map)
{
	char	*player;
	char	*char_below;

	player = ft_strchr(map->string, 'P');
	char_below = player + (map->width / SPRITE_SIZE) + 1;
	if (*char_below == 'C' || *char_below == '0')
	{
		*char_below = 'P';
		*player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*char_below == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

void	move_right(t_map *map)
{
	char	*player;

	player = ft_strchr(map->string, 'P');
	player++;
	if (*player == 'C' || *player == '0')
	{
		*player = 'P';
		*--player = '0';
		map->movements++;
		printf("Movements: %i\n", map->movements);
	}
	if (*player == 'E')
	{
		if (!ft_strchr(map->string, 'C'))
		{
			map->movements++;
			printf("Movements: %i\n", map->movements);
			close_window(map);
		}
	}
}

int	move_player(int keycode, t_map *map)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(map);
	if (keycode == XK_a || keycode == XK_Left)
		move_left(map);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(map);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(map);
	render_map(map);
	return (0);
}

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
	mlx_loop_hook(map.mlx, render_map, &map);
	map.movements = 0;
	mlx_hook(map.window, KeyPress, KeyPressMask, move_player, &map);
	mlx_hook(map.window, KeyRelease, KeyReleaseMask, escape_window, &map);
	mlx_hook(map.window, DestroyNotify, StructureNotifyMask, close_window,
		&map);
	mlx_loop(map.mlx);
	free(map.string);
	return (0);
}
