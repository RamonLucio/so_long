/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:42:23 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/17 12:58:24 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		get_line - get a line from buffer
** DESCRIPTION
** 		Uses ft_strchr to locate a newline character
** 		on buffer
** RETURN VALUE
** 		On success, returns a string containing
** 		the first line found on buffer
** 		If there is no newline character or else,
** 		returns NULL
*/

static char	*get_line(char **static_buffer)
{
	char	*ptr_to_newline_char;
	size_t	line_size;
	char	*line;
	char	*temp_buffer;

	if (*static_buffer == NULL)
		return (NULL);
	ptr_to_newline_char = ft_strchr(*static_buffer, '\n');
	if (ptr_to_newline_char)
	{
		line_size = (ptr_to_newline_char - *static_buffer) + 1;
		line = ft_substr(*static_buffer, 0, line_size);
		ptr_to_newline_char++;
		temp_buffer = ft_strdup(ptr_to_newline_char);
		free(*static_buffer);
		*static_buffer = ft_strdup(temp_buffer);
		free(temp_buffer);
		return (line);
	}
	else
		return (NULL);
}

/*
** NAME
** 		assign_line - assign a string to the static variable line
** DESCRIPTION
** 		Receive bytes read from a previous call to read on file descriptor,
** 		and the addresses of the static variables static_buffer, buffer
** 		and line, which were initialized in get_next_line.
**
** 		If read was successfully called, join buffer to static_buffer,
** 		call get_line to check if there is a line on the string created.
** 		If a line was found, assign it to static variable line.
**
** 		If read returned EOF, and there is a string stored on static_buffer,
** 		assign it to line and set static_buffer to NULL.
*/

static void	assign_line(int bytes, char **sta_buf, char **buf, char **line)
{
	char	*temp;

	if (bytes > 0)
	{
		if (*sta_buf == NULL)
			*sta_buf = ft_strdup("");
		temp = ft_strjoin(*sta_buf, *buf);
		free(*sta_buf);
		*sta_buf = ft_strdup(temp);
		free(temp);
		*line = get_line(sta_buf);
	}
	free(*buf);
	if (bytes <= 0 && *sta_buf != NULL)
	{
		if (**sta_buf != '\0')
			*line = ft_strdup(*sta_buf);
		free(*sta_buf);
		*sta_buf = NULL;
	}
}

/*
** NAME
** 		get_next_line
** DESCRIPTION
** 		A function which returns a line read from a
** 		file descriptor
** RETURN VALUE
** 		Read line: correct behavior
** 		NULL: nothing else to read or an error occurred
*/

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*static_buffer;
	char			*line;
	int				bytes_read;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(&static_buffer);
	while (line == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		assign_line(bytes_read, &static_buffer, &buffer, &line);
		if (bytes_read <= 0 && static_buffer == NULL)
			break ;
	}
	return (line);
}
