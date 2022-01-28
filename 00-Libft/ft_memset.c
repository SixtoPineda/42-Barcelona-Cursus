/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:37:56 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/10 14:37:58 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*sb;
	unsigned char	str;
	size_t			i;

	sb = (unsigned char *)b;
	str = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*sb = str;
		sb++;
		i++;
	}
	return (b);
}
