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
	- Obtain the num of dig
	- From integer to hex automatically as chars to obtain the string
*/

static char	*inv(char *aux, int i);
static char	*int2hex(long int n, int numdig);
static char	*empty(void);

char	*ft_itoa_upx(long int n)
{
	long int	aux;
	int			numdig;
	char		*str;

	aux = n;
	numdig = 0;
	while (aux != 0)
	{
		aux = aux / 10;
		numdig++;
	}
	if (numdig == 0)
		return (empty());
	str = int2hex(n, numdig);
	return (str);
}

static char	*int2hex(long int n, int numdig)
{
	int		i;
	int		p;
	char	*aux;

	i = 0;
	aux = (char *) malloc((numdig + 1) * sizeof(char));
	while (n != 0)
	{
		p = n % 16;
		n = n / 16;
		if (p <= 9)
			aux[i++] = p + '0';
		else
			aux[i++] = (p - 10) + 'A';
	}
	aux[i] = '\0';
	return (inv(aux, i));
}

static char	*inv(char *aux, int i)
{
	char	*str;
	int		j;
	int		w;

	j = 0;
	w = 0;
	i--;
	str = (char *) malloc((ft_strlen(aux) + 1) * sizeof(char));
	while (w < (ft_strlen(aux)))
	{
		str[j] = aux[i];
		i--;
		w++;
		j++;
	}
	str[j] = '\0';
	free(aux);
	return (str);
}

static char	*empty(void)
{
	char	*str;

	str = (char *) malloc((2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = 48;
	str[1] = '\0';
	return (str);
}
