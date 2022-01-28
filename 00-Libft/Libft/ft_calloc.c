/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:48:59 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:49:09 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
