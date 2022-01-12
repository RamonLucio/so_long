/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:41:45 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/13 00:01:44 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_error_and_exit(char *message)
{
	printf("%s\n", message);
	exit(1);
}

/*
	DESCRIPTION
		open map file and returns file descriptor
	RETURN VALUE
		If there is a valid map file, returns value of open() which
		is a file descriptor, a small, nonnegative integer that
		is used in subsequent system calls.
		
		If the specified file does not exist, returns an error message
		and exit program
*/

int	open_map(int argc, char *argv[])
{
	int		file_descriptor;
	char	*file_format;

	if (argc != 2)
		print_error_and_exit("Error\nThe program must have one argument\n");
	file_format = ft_strchr(argv[1], '.');
	if (!file_format)
		print_error_and_exit("Error\nFile format is invalid\n");
	else
	{
		if (ft_strncmp(file_format, ".ber", ft_strlen(file_format)) != 0)
			print_error_and_exit("Error\nFile format is invalid");
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("Error\n");
		exit(1);
	}
	return (file_descriptor);
}

/*
	DESCRIPTION
		Read map string from file
	RETURN VALUE
		Returns the content of file descriptor or
		else an empty string
*/

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
