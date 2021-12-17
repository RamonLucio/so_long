/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:30:05 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 15:21:00 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		tolower, tolower_l -- upper case to lower case letter conversion
** DESCRIPTION
** 		The tolower() function converts an upper-case letter to the
** 		corresponding lower-case letter.  The argument must be representable
** 		as an unsigned char or the value of EOF.
** RETURN VALUES
** 		If the argument is an upper-case letter, the tolower() function
** 		returns the corresponding lower-case letter if there is one; other-
** 		wise, the argument is returned unchanged.
*/

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	else
		return (c);
}
