/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:51 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 19:57:05 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		ft_strtrim -- 'trim' a given string
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns a copy of
** 		’s1’ with the characters specified in ’set’ removed
** 		from the beginning and the end of the string.
** RETURN VALUE
** 		The trimmed string. NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first_index;
	size_t	last_index;
	char	*str;

	first_index = 0;
	while (s1[first_index] && ft_strchr(set, s1[first_index]))
		first_index++;
	last_index = ft_strlen(s1) - 1;
	while (last_index && s1[last_index] && ft_strchr(set, s1[last_index]))
		last_index--;
	str = ft_substr(s1, first_index, (last_index - first_index + 1));
	return (str);
}
