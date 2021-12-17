/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:37 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:50:27 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strncmp -- compare strings
** DESCRIPTION
** 		The strncmp() functions lexicographically compare the
** 		null-terminated strings s1 and s2.
**
** 		The strncmp() function compares not more than n characters.
** 		Because strncmp() is designed for comparing strings rather than
** 		binary data, characters that appear after a `\0' character are not
** 		compared.
** RETURN VALUES
** 		The strncmp() function returns an integer greater
** 		than, equal to, or less than 0, according as the string s1 is
** 		greater than, equal to, or less than the string s2.  The comparison
** 		is done using unsigned characters, so that `\200' is greater than
** 		`\0'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	while (n--)
	{
		if ((*string1 != *string2) || *string1 == '\0' || *string2 == '\0')
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	return (0);
}
