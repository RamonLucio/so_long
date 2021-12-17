/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:05 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:24:15 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strchr -- locate character in string
** DESCRIPTION
** 		The strchr() function locates the first occurrence of c (converted
** 		to a char) in the string pointed to by s.  The terminating null
** 		character is considered to be part of the string; therefore if c is
** 		`\0', the functions locate the terminating `\0'.
** RETURN VALUES
** 		The function strchr() returns a pointer to the located character,
** 		or NULL if the character does not appear in the
** 		string.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	character;

	ptr = (char *) s;
	character = (char) c;
	while (*ptr)
	{
		if (*ptr == character)
			return (ptr);
		ptr++;
	}
	if (*ptr == character)
		return (ptr);
	return (NULL);
}
