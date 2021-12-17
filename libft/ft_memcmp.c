/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:14 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 16:05:36 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		memcmp -- compare byte string
** DESCRIPTION
** 		The memcmp() function compares byte string s1 against byte string
** 		s2.  Both strings are assumed to be n bytes long.
** RETURN VALUES
**      The memcmp() function returns zero if the two strings are identi-
**      cal, otherwise returns the difference between the first two differ-
**      ing bytes (treated as unsigned char values, so that `\200' is
**      greater than `\0', for example).  Zero-length strings are always
**      identical.  This behavior is not required by C and portable code
**      should only depend on the sign of the returned value.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	while (n--)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	return (0);
}
