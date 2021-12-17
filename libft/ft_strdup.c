/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:29:11 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 16:56:44 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		strdup -- save a copy of a string
** DESCRIPTION
** 		The strdup() function allocates sufficient memory for a copy of the
** 		string s1, does the copy, and returns a pointer to it.  The pointer
** 		may subsequently be used as an argument to the function free(3).
** RETURN VALUE
** 		On  success, strdup() returns a pointer to the duplicated
** 		string. If insufficient memory is available, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = (char *) malloc(len);
	if (ptr != NULL)
		ft_strlcpy(ptr, s1, len);
	return (ptr);
}
