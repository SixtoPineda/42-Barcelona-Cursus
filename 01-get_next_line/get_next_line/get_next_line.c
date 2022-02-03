/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:03:32 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/03 23:02:14 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

/*
	--> Function that returns the line read from a file descriptor "fd".
	
 */
static int	check_val(int val);
char		*ft_strchr(char *str, int val);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
static char	*strcpylen(char *str, char const *s, unsigned int start, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*aux;
	int			file_data;
	int			size_line;
	
	//---------------------------
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//------------------------------
	file_data = 1;
	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (aux == NULL)
			return (NULL);
	while (ft_strchr(buf, '\n') == NULL && file_data > 0)
	{
		file_data = read(fd, aux, BUFFER_SIZE);
		if (file_data <= 0)
		{
			free(aux);
			return (NULL);
		}
		aux[file_data] = '\0';
		buf = ft_strjoin(buf, aux);
	}
	if (buf == NULL || buf[0] == '\0')
	{
		free(aux);
		free(buf);
		return (NULL);
	}
	
	int i = 0;
	size_line = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		size_line++;
		i++;
	}
	size_line++;
	line = (char *)malloc(size_line * sizeof (char));
	/* i = 0;
	while (i < size_line)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0'; */
	line = ft_substr(buf, 0, size_line);
	buf = ft_substr(buf, size_line, ft_strlen(buf) - size_line);
	free(aux);
	return (line);
}

/*  int	main(void)
{
	int		fd;	
	int		file_data;
	char	*re;
	int		i;

	printf("files/41_no_nl: \n");
	fd = open("gnlTester/files/41_no_nl", O_RDWR);
	if (fd < 0)
		return (0);
	re = get_next_line(fd);
	printf("\n1:%s", re);
	printf("................\n");
	
	re = get_next_line(fd);
	printf("2:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("3:%s", re);
	printf("................\n");

	re = get_next_line(fd);
	printf("4:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("5:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("6:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("7:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("8:%s", (re));
	printf("................\n");

	re = get_next_line(fd);
	printf("9:%s", (re));
	printf("................\n");

	free(re);
	close(fd);
} */



size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (src[num] != '\0')
		num++;
	if (dstsize != 0)
	{
		while ((i < dstsize - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (num);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//-----------------Strchr----------------
static int	check_val(int val)
{
	int	aux;

	aux = val / 256;
	if (val > 0)
	{
		while (aux > 0)
		{
			val = val - 256;
			aux--;
		}
	}
	return (val);
}

char	*ft_strchr(char *str, int val)
{
	val = check_val(val);
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == val)
			return ((char *)str);
		str++;
	}
	if (*str == val)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len > size)
		return (src_len + size);
	while ((src[i] != '\0') && ((dest_len + 1) < size))
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	if (src[i] == '\0')
		return (dest_len);
	return (dest_len + (src_len - (i)));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (s1 == NULL)
		return ((char *)s2);
	s1_len = (size_t)ft_strlen((char *)s1);
	s2_len = (size_t)ft_strlen((char *)s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s1 == NULL || s2 == NULL || str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(&str[s1_len], s2, s2_len + 1);
	return (str);
}

static char	*strcpylen(char *str, char const *s, unsigned int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (s[0] == 0 || len == 0 || start > (unsigned int)ft_strlen(s))
	{
		str = (char *) malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if ((int)len > ft_strlen(s))
		size = ft_strlen(s) + 1 - start;
	else if (ft_strlen(s) - start < len)
		size = (ft_strlen(s) - start) + 1;
	else
		size = len + 1;
	str = (char *) malloc((size) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = strcpylen(str, s, start, size - 1);
	return (str);
}
