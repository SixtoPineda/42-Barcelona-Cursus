/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:54:28 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/09 15:57:23 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	str: contiene la "string" que se le pasa a "printf" 
	argptr: lista de argumentos pasados, por eso tiene que ser de tipo va_list
				(printf("str", argptr))
	
	va_arg(): nos da aquello a lo que apunta "argptr" con el "type" asociado y pasa a la siguiente
		posicion del puntero "argptr"




*/
#include <stdio.h>


int	ft_printf(const char *str, ...)
{
	va_list	argptr;

	if (str == NULL)
		return (0);
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			if(ft_strncmp(str, "%d", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el decimal asociado a: %d\n", c);
			}
			/* else if (ft_strncmp(str, "%c", 2) == 0)
			{
				char	c = (char) va_arg(argptr, int);
				printf("Detecta el char asociado a: %c\n", c);
			}
			else if (ft_strncmp(str, "%s", 2) == 0)
			{
				char	*c = va_arg(argptr, char *);
				printf("Detecta el string asociado a: %s\n", c);
			}
			else if (ft_strncmp(str, "%p", 2) == 0)
			{
				void	*c = va_arg(argptr, void *);
				printf("Detecta el puntero asociado a(imprimir el valor de un puntero): %p\n", c);
			}
			else if (ft_strncmp(str, "%i", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el Entero asociado a: %i\n", c);
			}
			else if (ft_strncmp(str, "%u", 2) == 0)
			{
				int	c = va_arg(argptr, unsigned int);
				printf("Detecta el decimal sin signo asociado a: %u\n", c);
			}
			else if (ft_strncmp(str, "%x", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el hexa en minusculas asociado a: %x\n", c);
			}
			else if (ft_strncmp(str, "%X", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el hexa en mayusculas asociado a: %X\n", c);
			}
			else if (ft_strncmp(str, "%%", 2) == 0)
			{
				char	c = (char) va_arg(argptr, int);
				printf("Detecta el hexa en mayusculas asociado a: %c\n", c);
			} */

		}
		str++;
	}
	va_end(argptr);
	return (0);
}

int	main(void)
{
/* 	char	*str = "hola";
	char	c = 's'; */
	int		n = 55;
/* 	char	*ptr;
	ptr = &c;
	// int	*ptr;
	// ptr = &n;
	int		entero = 19;
	unsigned int	ui = 1;
	int		hex_min = -3455;
	int		hex_may = 555;
	char	por = '%'; */
	/* ft_printf("d: %d\nc: %c\ns: %s\npunter: %p\nEntero: %i\nUnsigned int: %u\nHex_min: %x\nHex_may: %X\nPorcentaje: %%", n, c, str, ptr, entero, ui,  hex_min, hex_may, por);
 */
	ft_printf("d: %d\n", n);
}