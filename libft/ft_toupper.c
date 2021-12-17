/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:30:10 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:19:07 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		toupper, -- lower case to upper case letter conversion
** DESCRIPTION
** 		The toupper() function converts a lower-case letter to the corre-
** 		sponding upper-case letter.  The argument must be representable as
** 		an unsigned char or the value of EOF.
** RETURN VALUES
**      If the argument is a lower-case letter, the toupper() function
**      returns the corresponding upper-case letter if there is one; other-
**      wise, the argument is returned unchanged.
*/

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}
