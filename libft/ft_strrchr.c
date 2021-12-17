/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:47 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:41:38 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strrchr -- locate character in string
** DESCRIPTION
** 		The strrchr() function locates the last occurrence of c (converted
** 		to a char) in the string pointed to by s.  The terminating null
** 		character is considered to be part of the string; therefore if c is
** 		`\0', the functions locate the terminating `\0'.
** RETURN VALUES
** 		The function strrchr() returns a pointer to the located character,
** 		or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	character;
	char	*return_value;

	ptr = (char *) s;
	character = (char) c;
	return_value = NULL;
	while (*ptr)
	{
		if (*ptr == character)
			return_value = ptr;
		ptr++;
	}
	if (*ptr == character)
		return (ptr);
	return (return_value);
}
