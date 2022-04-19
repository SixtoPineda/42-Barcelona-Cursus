/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:16:34 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 14:16:40 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Use "set" as Dicc of symb inside s1 to cut 
	at the beginning and the end of s1
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	end = (ft_strlen((char *)s1) - 1);
	while (s1[start] && ft_strchr((char *)set, (int)s1[start]))
		start++;
	if (s1[start] == '\0' || s1[0] == '\0')
	{
		str = (char *) malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (end >= 0 && ft_strchr((char *)set, (int)s1[end]))
		end--;
	str = (char *) malloc((end - start + 2) * sizeof(char));
	if (s1 == NULL || str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[start], (end - start + 2));
	return (str);
}
