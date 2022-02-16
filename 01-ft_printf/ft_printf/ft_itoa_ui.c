/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:21 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:50:28 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	
*/

static char	obtain_digit(unsigned long int n, int numdig, int *j, int aux)
{		
	int				dig;
	int				cont;
	int long		numodul;
	int				i;

	i = *j - aux;
	*j = *j + 1;
	numodul = 1;
	cont = 0;
	while (cont < (numdig - 1))
	{
		numodul = numodul * 10;
		cont++;
	}
	cont = 0;
	while (cont <= i)
	{
		numodul = numodul / 10;
		cont++;
	}
	dig = (n % (numodul * 10)) / numodul;
	*j = *j - 1;
	return (dig + '0');
}

static char	*int_to_char(unsigned long int n, int numdig)
{
	char	*str;
	int		i;
	int		aux;

	i = 0;
	aux = 1;
	str = (char *) malloc((numdig + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < numdig)
		str[i++] = obtain_digit(n, numdig, &i, aux);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_ui(unsigned long int n)
{
	unsigned long int		aux;
	int						numdig;
	char					*str;

	numdig = 0;
	if (n == 0)
	{
		str = (char *) malloc((2) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	aux = n;
	while (aux != 0)
	{
		aux = aux / 10;
		numdig++;
	}
	return (int_to_char(n, numdig));
}
