/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:03:48 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/07 12:34:38 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	-----------------Strlcpy----------------
	copy src inside dest, only de dstsize number
	of chars
*/

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	num = ft_strlen(src);
	if (dstsize != 0)
	{
		while ((i < dstsize - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (num);
}

/*
	-----------------Strlen----------------
	return the lenght of the string
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
	-----------------Strchr----------------
	+ return the position in memory where we
		find the "val" (char)
*/

char	*ft_strchr(char *str, int val)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == val)
			return ((char *)str);
		str++;
	}
	if (*str == val)
		return ((char *)str);
	return (NULL);
}

/*
	-----------------Strlcat----------------
	Appends the NUL-terminated string src to the end of dst,
		only add "size" chars of src
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len > size)
		return (src_len + size);
	while ((src[i] != '\0') && ((dest_len + 1) < size))
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	if (src[i] == '\0')
		return (dest_len);
	return (dest_len + (src_len - (i)));
}

/*
	-----------------Strcpylen----------------
	Copy in "str" the string "s" since "s[start]" while len
*/

char	*strcpylen(char *str, char const *s, unsigned int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
