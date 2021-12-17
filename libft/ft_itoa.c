/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:58:31 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/30 13:56:47 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static char	*ft_reverse_string(char *s)
{
	int		first_index;
	int		last_index;
	char	temp;

	first_index = 0;
	last_index = ft_strlen(s) - 1;
	while (first_index < last_index)
	{
		temp = s[first_index];
		s[first_index] = s[last_index];
		s[last_index] = temp;
		first_index++;
		last_index--;
	}
	return (s);
}

/*
** NAME
** 		ft_itoa - convert integer to string
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns a string
** 		representing the integer received as an argument.
** 		Negative numbers must be handled.
** RETURN VALUE
** 		The string representing the integer. NULL if the
** 		allocation fails.
*/

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = malloc(sizeof(char) * (ft_count_digits(n) + 1));
	if (!s)
		return (NULL);
	sign = n;
	if (n < 0)
		n = -n;
	i = 0;
	while (n)
	{
		s[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse_string(s);
	return (s);
}
