/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:03:57 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/08 10:33:43 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*-------------------------Header------------------------------------*/
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define NUM_FILES 700

/*------------------------Function-----------------------------------*/
char	*get_next_line(int fd);

/*------------------------Utils-----------------------------------*/
char	*ft_strchr(char *str, int val);
int		ft_strlen(char *str);
char	*strcpylen(char *str, char const *s, unsigned int start, int len);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/*------------------------Bonus-----------------------------------*/

#endif
