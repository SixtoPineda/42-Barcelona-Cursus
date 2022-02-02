/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:55:17 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:55:20 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return ;
	while (i < s_len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
