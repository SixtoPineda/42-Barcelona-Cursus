/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:17:13 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/09 15:55:23 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*-------------------------Header------------------------------------*/
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
/*------------------------ft_printf-----------------------------------*/
int		ft_printf(const char *str, ...);

/*------------------------Utils - ft_printf-----------------------------------*/
void	ft_putchar(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
/*------------------------Bonus-----------------------------------*/

#endif
