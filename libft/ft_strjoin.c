/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:16 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 19:46:10 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		ft_strjoin -- concatenate two strings
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns a new string,
** 		which is the result of the concatenation of ’s1’ and ’s2’.
** RETURN VALUE
** 		The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_size;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_size = s1_len + s2_len + 1;
	str = (char *) malloc(str_size * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, str_size);
	return (str);
}
