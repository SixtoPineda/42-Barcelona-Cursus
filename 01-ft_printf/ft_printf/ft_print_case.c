/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:43:22 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/13 21:09:51 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

*/

void	d_i_case(va_list argptr, int *chr_printed, const char **str)
{
	char	*str_number;
	int		c;
	int		i;

	i = 0;
	c = va_arg(argptr, int);
	str_number = ft_itoa(c);
	while (str_number[i])
	{
		ft_putchar(str_number[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(str_number);
	free(str_number);
	*str = *str + 2;
}

void	c_case(va_list argptr, int *chr_printed, const char **str)
{
	char	c;

	c = (char)va_arg(argptr, int);
	ft_putchar(c);
	*chr_printed = *chr_printed + 1;
	*str = *str + 2;
}

void	s_case(va_list argptr, int *chr_printed, const char **str)
{
	char	*c;
	char	*aux;
	int		i;

	i = 0;
	aux = "(null)";
	c = va_arg(argptr, char *);
	if (!c)
		c = aux;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(c);
	*str = *str + 2;
}

void	perc_case(int *chr_printed)
{
	write(1, "%", 1);
	*chr_printed = *chr_printed + 1;
}

void	p_case(va_list argptr, int *chr_printed)
{
	char				*str_number;
	unsigned long int	w;
	int					i;

	i = 0;
	w = va_arg(argptr, long int);
	str_number = ft_itoa_h(w);
	while (str_number[i])
	{
		ft_putchar(str_number[i]);
		i++;
	}
	*chr_printed = *chr_printed + ft_strlen(str_number);
	free(str_number);
}
