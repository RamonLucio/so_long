/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:27 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 10:15:58 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		memmove -- copy byte string
** DESCRIPTION
** 		The memmove() function copies len bytes from string src to string
** 		dst.  The two strings may overlap; the copy is always done in a
** 		non-destructive manner.
** RETURN VALUES
** 		The memmove() function returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destination;
	const char	*source;

	if ((!dst && !src) || !len)
		return (dst);
	destination = (char *) dst;
	source = (char *) src;
	if (destination < source)
		while (len--)
			*destination++ = *source++;
	else
	{
		destination += (len - 1);
		source += (len - 1);
		while (len--)
			*destination-- = *source--;
	}
	return (dst);
}
