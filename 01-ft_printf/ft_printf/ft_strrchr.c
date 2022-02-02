/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:55:57 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/12 11:55:58 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_val(int val)
{
	int	aux;

	aux = val / 256;
	if (val > 0)
	{
		while (aux > 0)
		{
			val = val - 256;
			aux--;
		}
	}
	return (val);
}

char	*ft_strrchr(const char *str, int ch)
{
	int		src_len;

	ch = check_val(ch);
	src_len = 0;
	while (str[src_len])
		src_len++;
	str = (str + (src_len - 1));
	if (*(str + 1) == ch)
		return ((char *)(str + 1));
	while (*str && src_len > 0)
	{
		if (*str == ch)
			return ((char *)str);
		str--;
		src_len--;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}
