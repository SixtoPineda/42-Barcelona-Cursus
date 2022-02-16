/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_case2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:43:22 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/16 20:40:14 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

*/

void	u_case(va_list argptr, int *chr_printed)
{
	char			*str_number;
	unsigned int	c;
	unsigned int	imax;
	int				i;

	i = 0;
	imax = 4294967295;
	c = va_arg(argptr, long int);
	if (c >= imax)
		c = (imax + 1) + c;
	str_number = ft_itoa_ui(c);
	while (str_number[i])
	{
		ft_putchar(str_number[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(str_number);
	free(str_number);
}

void	x_case(va_list argptr, int *chr_printed)
{
	char		*str_number;
	long int	z;
	int			w;
	int			i;

	w = va_arg(argptr, long int);
	z = 0;
	i = 0;
	if (w < 0)
		z = 4294967296 + w;
	else
		z = w;
	str_number = ft_itoa_x(z);
	while (str_number[i])
	{
		ft_putchar(str_number[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(str_number);
	free(str_number);
}

void	upx_case(va_list argptr, int *chr_printed)
{
	char		*str_number;
	int			w;
	long int	z;
	int			i;

	i = 0;
	z = 0;
	w = va_arg(argptr, long int);
	if (w < 0)
		z = 4294967296 + w;
	else
		z = w;
	str_number = ft_itoa_upx(z);
	while (str_number[i])
	{
		ft_putchar(str_number[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(str_number);
	free(str_number);
}
