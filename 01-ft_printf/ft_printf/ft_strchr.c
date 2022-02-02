/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:55:43 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/12 11:55:45 by spineda-         ###   ########.fr       */
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

char	*ft_strchr(const char *str, int val)
{
	val = check_val(val);
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
