/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:53:59 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:54:05 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = size - 1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (size == 0)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, size);
	}
	else
	{
		while (i)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
		((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
