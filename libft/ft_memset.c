/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:33 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 10:06:05 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		memset -- fill a byte string with a byte value
** DESCRIPTION
** 		The memset() function writes len bytes of value c
** 		(converted to an unsigned char) to the string b.
** RETURN VALUES
** 		The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len--)
		*ptr++ = (unsigned char) c;
	return (b);
}
