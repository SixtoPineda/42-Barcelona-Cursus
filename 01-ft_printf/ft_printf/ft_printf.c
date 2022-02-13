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
	
	va_arg(): nos da aquello a lo que apunta "argptr" con el "type" asociado y pasa a la siguiente
		posicion del puntero "argptr"




*/

#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int	chr_printed;
	char *str_number;
	char aux[] = "(null)";
	chr_printed = 0;

	if (!str)
		return (-1);
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			if(ft_strncmp(str, "%d", 2) == 0 || ft_strncmp(str, "%i", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				// printf("Detecta el decimal asociado a: %d\n", c);
				str_number = ft_itoa(c);
				int	i = 0;
				while (str_number[i])
				{
					ft_putchar(str_number[i]);
					i++;
				}
				chr_printed = chr_printed + ft_strlen(str_number);
				free(str_number);
				str = str + 2;
			}
			else if (ft_strncmp(str, "%c", 2) == 0)
			{
				char	c = (char) va_arg(argptr, int);
				// printf("Detecta el char asociado a: %c\n", c);
				ft_putchar(c);
				chr_printed++;
				str = str + 2;

			}
			else if (ft_strncmp(str, "%s", 2) == 0)
			{
				char	*c = va_arg(argptr, char *);
				// printf("Detecta el string asociado a: %s\n", c);
				if (!c)
				{
					c = aux;
				}
				int	i = 0;
				while (c[i])
				{
					ft_putchar(c[i]);
					i++;
				}
				chr_printed = chr_printed + ft_strlen(c);
				str = str + 2;
			} 
			else if (ft_strncmp(str, "%p", 2) == 0)
			{ 
				unsigned long int	c = va_arg(argptr, unsigned long int);
				printf("C: %lu\n", c);
				//c contiene al valor a printar
				//Pasar char c y cambiar de base a hexadecimal primero
				str = str + 2;
			}
			else if (ft_strncmp(str, "%u", 2) == 0)
			{
				int	c = va_arg(argptr, unsigned int);
				unsigned int	max = 4294967295;
				// printf("Detecta el decimal asociado a: %d\n", c);
				if (c < 0)
					c = max + c;
				//crear itoa para el unsigned int
				str_number = ft_itoa((int)c);
				int	i = 0;
				while (str_number[i])
				{
					ft_putchar(str_number[i]);
					i++;
				}
				chr_printed = chr_printed + ft_strlen(str_number);
				free(str_number);
				str = str + 2;
			}
			/*
			else if (ft_strncmp(str, "%x", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el hexa en minusculas asociado a: %x\n", c);
			}
			else if (ft_strncmp(str, "%X", 2) == 0)
			{
				int	c = va_arg(argptr, int);
				printf("Detecta el hexa en mayusculas asociado a: %X\n", c);
			}*/
			else if (ft_strncmp(str, "%%", 2) == 0)
			{
				va_arg(argptr, int);
				write(1, "%", 1); 
				chr_printed = chr_printed + 1;
				str = str + 2;
			}
			

		}
		else
		{
			ft_putchar(*str);
			str++;
			chr_printed++;
		}
		
	}
	
	va_end(argptr);
	return (chr_printed);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int val;
// 	int mio;
// 	// int	c = -2;
// 	// char	*str = "hola";
// /* 	
// 	char	*str = "hola";
// 	char	*ptr;
// 	ptr = &c;
// 	// int	*ptr;
// 	// ptr = &n;
// 	int		entero = 19;
// 	unsigned int	ui = 1;
// 	int		hex_min = -3455;
// 	int		hex_may = 555;
// 	char	por = '%';
// 	ft_printf("d: %d\nc: %c\ns: %s\npunter: %p\nEntero: %i\nUnsigned int: %u\nHex_min: %x\nHex_may: %X\nPorcentaje: %%", n, c, str, ptr, entero, ui,  hex_min, hex_may, por);
//  */
// 	// val = ft_printf("s: (%s) --> OK\n", str);
// 	// printf("val mio str: %d\n", val);
// 	// val = printf("s: (%s) --> OK\n", str);
// 	// printf("val str: %d\n", val);
	
// 	val = printf("El %% \n");
// 	mio = ft_printf("Yo %% \n");
// 	printf("Suyo: %d\n", val);
// 	printf("Mio: %d\n", mio);

// }
