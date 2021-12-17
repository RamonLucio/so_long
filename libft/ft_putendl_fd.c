/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:42:48 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/30 15:37:00 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** 		Outputs the string ’s’ to the given file
** 		descriptor, followed by a newline.
*/

void	ft_putendl_fd(char *s, int fd)
{
	char	new_line;

	new_line = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &new_line, 1);
}
