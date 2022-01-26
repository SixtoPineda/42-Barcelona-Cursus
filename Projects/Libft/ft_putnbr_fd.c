/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:54:56 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:55:01 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	
*/

void	ft_putnbr_fd(int n, int fd)
{
	int		aux;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putstr_fd("147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		aux = n / 10;
		if (aux != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
