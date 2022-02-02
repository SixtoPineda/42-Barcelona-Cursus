/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:47:58 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:48:23 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Iterate while we see ' '(spaces) or tabs...
	- if we find a sign, check if it's negative to return
		the final int with "int * -1" and go to next pos with i++
		
	"while ((str[i] >= '0') && (str[i] <= '9'))"
		+ in case is other char we don't do the "while" an return "0 * sign"
		+ in case is a number iterate and sum the num t
			o "num * 10" for correct pos of number
 */

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	int				num;
	unsigned char	*str;

	str = (unsigned char *)nptr;
	sign = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
