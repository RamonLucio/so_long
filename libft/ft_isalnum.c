/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:27:38 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/26 20:21:06 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		isalnum -- alphanumeric character test
** DESCRIPTION
** 		The isalnum() function tests for any character for which isalpha(3)
** 		or isdigit(3) is true.  The value of the argument must be repre-
** 		sentable as an unsigned char or the value of EOF.
** RETURN VALUES
** 		The isalnum() function returns zero if the character tests false
** 		and returns non-zero if the character tests true.
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
