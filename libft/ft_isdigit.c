/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:27:55 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/27 10:05:07 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		isdigit -- decimal-digit character test
** DESCRIPTION
** 		The isdigit() function tests for a decimal digit character.
** 		Regardless of locale, this includes the following characters only:
**
** 		``0''         ``1''         ``2''         ``3''         ``4''
** 		``5''         ``6''         ``7''         ``8''         ``9''
**
** 		The value of the argument must be representable as an unsigned char
** 		or the value of EOF.
** RETURN VALUES
** 		The isdigit() function returns zero if the character
** 		tests false and return non-zero if the character tests true.
*/

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}
