/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:19 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 11:20:44 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		memcpy -- copy memory area
** DESCRIPTION
** 		The memcpy() function copies n bytes from memory area src to memory
** 		area dst. If dst and src overlap, behavior is undefined. Applications
** 		in which dst and src might overlap should use memmove(3) instead.
** RETURN VALUES
** 		The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if ((!dst && !src) || !n)
		return (dst);
	destination = (char *) dst;
	source = (char *) src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
