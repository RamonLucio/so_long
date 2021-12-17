/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:20 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:50:59 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strlcat -- size-bounded string concatenation
** DESCRIPTION
** 		strlcat() appends string src to the end of dst.  It will append at most
** 		dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
** 		unless dstsize is 0 or the original dst string was longer than dstsize
** 		(in practice this should not happen as it means that either dstsize is
** 		incorrect or that dst is not a proper string).
** 		If the src and dst strings overlap, the behavior is undefined.
** RETURN VALUES
** 		strlcat() returns the total length of the string it tried to create.
** 		That means the initial length of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		size;
	size_t		dst_len;

	destination = dst;
	source = src;
	size = dstsize;
	while (size-- && *destination != '\0')
		destination++;
	dst_len = destination - dst;
	size = dstsize - dst_len;
	if (size == 0)
		return (dst_len + ft_strlen(source));
	while (size-- > 1 && *source != '\0')
		*destination++ = *source++;
	*destination = '\0';
	while (*source++)
		;
	return (dst_len + (source - src) - 1);
}
