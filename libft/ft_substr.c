/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:30:00 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 19:41:28 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		ft_substr -- returns a substring from the string ’s’
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns a substring
** 		from the string ’s’.
** 		The substring begins at index ’start’ and is of
** 		maximum size ’len’.
** RETURN VALUE
** 		The substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	copied_chars;
	size_t	str_len;
	char	*substr;

	str_len = ft_strlen(s);
	if (str_len > start)
	{
		copied_chars = 0;
		while ((copied_chars < len) && ((start + copied_chars) < str_len))
			copied_chars++;
		substr = (char *) malloc((copied_chars + 1) * sizeof(char));
	}
	else
		return (ft_strdup(""));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], copied_chars + 1);
	return (substr);
}
