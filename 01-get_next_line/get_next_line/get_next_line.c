/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:03:32 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/01 12:01:46 by syxtyn           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*buf;
	char	*str_data;
	int		size_line;
	int		file_data;
	static int		i = 0;
	int		j;
	int aux_buf;
	int read_previous_data;
	
	//---------------------------
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	//------------------------------
	j = 0;
	aux_buf = 0;
	size_line = 0;
	read_previous_data = 0;
	buf = (char *)malloc(BUFFER_SIZE * sizeof (char));
	int read_current_data = 0;
	read_current_data = read(fd, buf, BUFFER_SIZE + aux_buf);
 	while (read_current_data != read_previous_data)
	{
		/* printf("read_previous_data: %d  aux_buf: %d\n", read_previous_data, aux_buf); */
		read_previous_data = read_current_data;
		free(buf);
		aux_buf++;
		buf = (char *)malloc((BUFFER_SIZE + aux_buf) * sizeof (char));
		read_current_data = read(fd, buf, BUFFER_SIZE + aux_buf);
		
		printf("read_previous_data: %d  aux_buf: %d\n\n", read_previous_data, aux_buf);
	}

	//file_data = read(fd, buf, 44);
	printf("FINAL: read_previous_data: %d", read_previous_data);
	file_data = 41;

	if (file_data <= 0 || buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	file_data = i;
	while (buf[file_data] != '\n' && buf[file_data] != 0)
	{
		
		size_line++;
		file_data++;
/* 		printf("buf[file_data]: %c - size_line: %d - fiel_data: %d\n", buf[file_data-1], size_line, file_data);
 */	}
	if (file_data == i)
	{
		str_data = (char *)malloc((2) * sizeof (char));
		ft_strlcpy(str_data, "\n", 2);
		i++;
		free(buf);
		return (str_data);
	}
	else
		str_data = (char *)malloc((file_data) * sizeof (char));
	while (0 < size_line )
	{
		str_data[j] = buf[i];
		i++;
		j++;
		size_line--;
	}
	free(buf);
	return (str_data);
}

 int	main(void)
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
}
 