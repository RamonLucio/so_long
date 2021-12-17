/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:28:40 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/08/30 13:50:52 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** NAME
** 		ft_strcspn -- spans a string
** DESCRIPTION
** 		The ft_strcspn() function spans the initial part of the null-
** 		terminated string s as long as the character c do not occur.
** 		In other words, it computes the string array index of the first
** 		c character in s, else the index of the first null character.
** RETURN VALUE
** 		The ft_strcspn() function returns the number of characters spanned.
*/

static size_t	ft_strcspn(const char *s, char c)
{
	size_t	span;

	span = 0;
	while (*s && (*s != c))
	{
		s++;
		span++;
	}
	return (span);
}

/*
** NAME
** 		ft_strspn -- spans a string
** DESCRIPTION
** 		The ft_strspnstrspn() function spans the initial part of the null-
** 		terminated string s as long as the character c occur.  In other words,
** 		it computes the string array index of the first character of s
** 		which is other than c, else the index of the first null character.
** RETURN VALUE
** 		The ft_strspn() function returns the number of characters spanned.
*/

static size_t	ft_strspn(const char *s, char c)
{
	size_t	span;

	span = 0;
	while (*s && (*s == c))
	{
		s++;
		span++;
	}
	return (span);
}

/*
** NAME
** 		ft_count_tokens -- count tokens in a string
** DESCRIPTION
** 		This function is used to count sequential tokens in a null-terminated
** 		string. These tokens are separated in the string by the c character.
** RETURN VALUE
** 		The function returns the amount of tokens counted in the string.
*/

static size_t	ft_count_tokens(char const *s, char c)
{
	size_t	arr_size;

	arr_size = 0;
	while ((*s == c) && (*s != '\0'))
		s++;
	while (*s)
	{
		while ((*s != c) && (*s != '\0'))
			s++;
		arr_size++;
		while ((*s == c) && (*s != '\0'))
			s++;
	}
	return (arr_size);
}

/*
** NAME
** 		ft_split -- splits string in array of strings
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns an array
** 		of strings obtained by splitting ’s’ using the
** 		character ’c’ as a delimiter. The array must be
** 		ended by a NULL pointer.
** RETURN VALUE
** 		The array of new strings resulting from the split.
** 		NULL if the allocation fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*p;
	char	*p_start;
	size_t	i;

	p = ft_strdup(s);
	if (!p)
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * (ft_count_tokens(s, c) + 1));
	if (!arr)
		return (NULL);
	p_start = p;
	i = 0;
	while (*s)
	{
		s = p + ft_strspn(p, c);
		p = (char *) s + ft_strcspn(s, c);
		if (*p != '\0')
			*p++ = '\0';
		if (*s != '\0')
			arr[i++] = ft_strdup(s);
	}
	arr[i] = NULL;
	free(p_start);
	return (arr);
}
