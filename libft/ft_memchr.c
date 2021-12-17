/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:09 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:58:12 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		memchr -- locate byte in byte string
** DESCRIPTION
** 		The memchr() function locates the first occurrence of c (converted
** 		to an unsigned char) in string s.
** RETURN VALUES
** 		The memchr() function returns a pointer to the byte located, or
** 		NULL if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *) s;
	ch = (unsigned char) c;
	while (n--)
	{
		if (*ptr == ch)
			return ((void *) ptr);
		ptr++;
	}
	return (NULL);
}
