/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:16:52 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 14:16:57 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Reserva con malloc(3) memoria para devolver una
	string nueva basada en la string ’s’.
	La nueva string empieza en el índice ’start’ y
	tiene una longitud máxima ’len’.
 */

static char	*strcpylen(char *str, char const *s, unsigned int start, int len)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (s[0] == 0 || len == 0 || start > (unsigned int)ft_strlen(s))
	{
		str = (char *) malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if ((int)len > ft_strlen(s))
		size = ft_strlen(s) + 1 - start;
	else if (ft_strlen(s) - start < len)
		size = (ft_strlen(s) - start) + 1;
	else
		size = len + 1;
	str = (char *) malloc((size) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = strcpylen(str, s, start, size - 1);
	return (str);
}
