/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:26 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/17 14:30:40 by rlucio-l         ###   ########.fr       */
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
	const char	*source;
	size_t		destination_size;

	source = src;
	destination_size = dstsize;
	if (destination_size != 0)
	{
		while (--destination_size)
		{
			if (*source == '\0')
			{
				*dst++ = *source++;
				break ;
			}
			*dst++ = *source++;
		}
	}
	if (destination_size == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*source++)
			;
	}
	return (source - src - 1);
}
