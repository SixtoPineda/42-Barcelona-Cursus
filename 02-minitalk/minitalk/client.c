/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:53:59 by spineda-          #+#    #+#             */
/*   Updated: 2022/04/06 11:54:01 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		return (1);
	}
    ft_putstr_fd("Info sent: ", 1);
    ft_putnbr_fd(ft_strlen(argv[2]), 1);
    ft_putchar_fd('\n', 1);
}
