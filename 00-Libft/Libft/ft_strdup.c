/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:48:33 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/12 13:48:34 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*str;
	int		i;

	i = 0;
	len_s = 0;
	while (s[len_s])
		len_s++;
	str = (char *) malloc((len_s + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
