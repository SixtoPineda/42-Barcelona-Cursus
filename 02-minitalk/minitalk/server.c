/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:07 by spineda-          #+#    #+#             */
/*   Updated: 2022/04/06 11:54:09 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
/*

    - Print the PID of the server

*/

int	main(void)
{
	char	*pid;
	char	*serv_out;

	pid = ft_itoa(getpid());
	serv_out = ft_strjoin("Server PID: ", pid);
	ft_putstr_fd(serv_out, 1);
	ft_putchar_fd('\n', 1);
}
