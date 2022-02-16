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

# include <stdio.h>
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
char	*ft_itoa_h(unsigned long int n);
char	*ft_itoa_ui(unsigned long int n);
char	*ft_itoa_x(long int n);
char	*ft_itoa_upx(long int n);
/*------------------------Cases 1 - ft_printf--------------------------------*/
void	d_i_case(va_list argptr, int *chr_printed, const char **str);
void	c_case(va_list argptr, int *chr_printed, const char **str);
void	s_case(va_list argptr, int *chr_printed, const char **str);
void	perc_case(int *chr_printed);
void	p_case(va_list argptr, int *chr_printed);
/*------------------------Cases 2 - ft_printf---------------------------------*/
void	u_case(va_list argptr, int *chr_printed);
void	x_case(va_list argptr, int *chr_printed);
void	upx_case(va_list argptr, int *chr_printed);
/*------------------------Bonus----------------------------------------------*/

#endif
