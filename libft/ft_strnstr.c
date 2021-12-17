/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:43 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 16:09:20 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strnstr -- locate a substring in a string
** DESCRIPTION
** 		The strnstr() function locates the first occurrence of the null-
** 		terminated string needle in the string haystack, where not more
** 		than len characters are searched.  Characters that appear after a
** 		`\0' character are not searched.  Since the strnstr() function is a
** 		FreeBSD specific API, it should only be used when portability is
** 		not a concern.
** RETURN VALUES
** 		If needle is an empty string, haystack is returned; if needle
** 		occurs nowhere in haystack, NULL is returned; otherwise a pointer
** 		to the first character of the first occurrence of needle is
** 		returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*str_haystack;
	const char	*str_needle;
	size_t		needle_len;

	str_haystack = haystack;
	str_needle = needle;
	if (*str_needle != '\0')
	{
		needle_len = ft_strlen(needle);
		if ((*str_haystack == '\0') || len < 1)
			return (NULL);
		while (*str_haystack && (needle_len <= len--))
		{
			if (ft_strncmp(str_haystack, str_needle, needle_len) == 0)
				return ((char *) str_haystack);
			str_haystack++;
		}
		return (NULL);
	}
	return ((char *) str_haystack);
}
