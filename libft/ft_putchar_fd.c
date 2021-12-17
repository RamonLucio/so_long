/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:07:40 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/30 15:36:35 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** 		Outputs the character ’c’ to the given file
** 		descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
