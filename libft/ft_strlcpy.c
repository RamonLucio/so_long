/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:26 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 13:30:54 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strlcpy -- size-bounded string copying
** DESCRIPTION
** 		strlcpy() copies up to dstsize - 1 characters from the string src to
** 		dst, NUL-terminating the result if dstsize is not 0.
** 		If the src and dst strings overlap, the behavior is undefined.
** RETURN VALUES
** 		strlcpy() returns the total length of the string it tried to create.
** 		That means the length of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		destination_size;
	size_t		ch;

	destination = dst;
	source = src;
	destination_size = dstsize;
	if (destination_size != 0)
	{
		while (--destination_size)
		{
			ch = (*destination++ = *source++);
			if (ch == '\0')
				break ;
		}
	}
	if (destination_size == 0)
	{
		if (dstsize != 0)
			*destination = '\0';
		while (*source++)
			;
	}
	return (source - src - 1);
}
