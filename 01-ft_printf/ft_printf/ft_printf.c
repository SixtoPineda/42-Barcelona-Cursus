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
	str: contiene la "string" que se le pasa a "printf" 
	argptr: lista de argumentos pasados, por eso tiene que ser de tipo va_list
				(printf("str", argptr))
	
	va_arg(): nos da aquello a lo que apunta "argptr" 
		con el "type" asociado y pasa a la siguiente posicion del puntero "argptr"

*/

static int	print_param3(const char **str, va_list argptr, int chr_printed);
static int	print_param2(const char **str, va_list argptr, int chr_printed);
static int	print_param(const char *str, va_list argptr, int chr_printed);

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		chr_printed;

	chr_printed = 0;
	if (!str)
		return (-1);
	va_start(argptr, str);
	chr_printed = print_param(str, argptr, chr_printed);
	va_end(argptr);
	return (chr_printed);
}

static int	print_param(const char *str, va_list argptr, int chr_printed)
{
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_strncmp(str, "%d", 2) == 0 || ft_strncmp(str, "%i", 2) == 0)
				d_i_case(argptr, &chr_printed, &str);
			else if (ft_strncmp(str, "%c", 2) == 0)
				c_case(argptr, &chr_printed, &str);
			else if (ft_strncmp(str, "%s", 2) == 0)
				s_case(argptr, &chr_printed, &str);
			else
				chr_printed = print_param2(&str, argptr, chr_printed);
		}
		else
		{
			ft_putchar(*str);
			str++;
			chr_printed++;
		}
	}
	return (chr_printed);
}

static int	print_param2(const char **str, va_list argptr, int chr_printed)
{
	if (ft_strncmp(*str, "%%", 2) == 0)
	{
		perc_case(&chr_printed);
		*str = *str + 2;
	}
	else if (ft_strncmp(*str, "%p", 2) == 0)
	{
		p_case(argptr, &chr_printed);
		*str = *str + 2;
	}
	else if (ft_strncmp(*str, "%u", 2) == 0)
	{
		u_case(argptr, &chr_printed);
		*str = *str + 2;
	}
	else if ((ft_strncmp(*str, "%x", 2) == 0)
		|| (ft_strncmp(*str, "%X", 2) == 0))
	{
		chr_printed = print_param3(str, argptr, chr_printed);
		*str = *str + 2;
	}
	return (chr_printed);
}

static int	print_param3(const char **str, va_list argptr, int chr_printed)
{
	if (ft_strncmp(*str, "%x", 2) == 0)
	{
		x_case(argptr, &chr_printed);
	}
	else if (ft_strncmp(*str, "%X", 2) == 0)
	{
		upx_case(argptr, &chr_printed);
	}
	return (chr_printed);
}
