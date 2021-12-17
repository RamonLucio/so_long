/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:27:32 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 16:44:56 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		calloc -- memory allocation
** DESCRIPTION
** 		The calloc() function contiguously allocates enough space for count
** 		objects that are size bytes of memory each and returns a pointer to
** 		the allocated memory.  The allocated memory is filled with bytes of
** 		value zero.
** RETURN VALUES
** 		If successful, calloc() returns a pointer to allocated memory.
** 		If there is an error, they return a NULL pointer.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
