/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:54:40 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/10 12:54:42 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int str)
{
	if (!((str < 48) || ((str > 57) && (str < 65))
			|| ((str > 90) && (str < 97)) || (str > 122)))
		return (1);
	return (0);
}
