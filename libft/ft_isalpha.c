/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:27:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/26 20:27:27 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		isalpha -- alphabetic character test
** DESCRIPTION
** 		The isalpha() function tests for any character for which isupper(3)
** 		or islower(3) is true.  The value of the argument must be repre-
** 		sentable as an unsigned char or the value of EOF.
** RETURN VALUES
** 		The isalpha() function returns zero if the character tests false
** 		and returns non-zero if the character tests true.
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
