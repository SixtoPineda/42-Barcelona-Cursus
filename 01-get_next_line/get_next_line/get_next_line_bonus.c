/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:03:32 by spineda-          #+#    #+#             */
/*   Updated: 2022/02/08 10:31:40 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
	--> Function that returns the line read from a file descriptor "fd".
	+ check if there is a file or if the buffer_size is possible
	* read_line()
		+ aux: to be able to read the file
		+ While: to read the whole line and save it in buf while we don't find
			new line inside the buf or nothing is read
			- file_data: number of data read and saved in "aux"
				<0 : error
				=0 : nothing read
			- aux[file_data] = '\0': to join the data read with buf and
				update the buf with the new data.
		+ Free "aux" only if it's not done before, inside the while
	* chec_read()
		+ Nothing is read or we are at the end of the file
	+ Check if the line is empty
	+ Obtain the size of the line read inside buf
	+ Copy the line (since the found \n or \0 inside the buf data)
	+ Update the buf, put all data since we find \n to the end
		of the data read 

 */
static char	*read_line(char *buf, int fd);
static char	*check_read(char *buf);
static char	*ft_strjoin(char *s1, char *s2);
static char	*ft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	static char	*buf[NUM_FILES];
	char		*line;
	char		*buf_update;
	int			size_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = read_line(buf[fd], fd);
	if (check_read(buf[fd]) == NULL)
		return (NULL);
	size_line = 0;
	if (buf[fd][size_line] == '\0')
		return (NULL);
	while (buf[fd][size_line] != '\n' && buf[fd][size_line] != '\0')
		size_line++;
	size_line++;
	line = ft_substr(buf[fd], 0, size_line);
	buf_update = ft_substr(buf[fd], size_line, ft_strlen(buf[fd]) - size_line);
	free(buf[fd]);
	buf[fd] = buf_update;
	return (line);
}

static char	*read_line(char *buf, int fd)
{
	char		*aux;
	int			file_data;

	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (aux == NULL)
		return (NULL);
	file_data = 1;
	while (ft_strchr(buf, '\n') == NULL && file_data > 0)
	{
		file_data = read(fd, aux, BUFFER_SIZE);
		if (file_data <= 0)
		{
			free(aux);
			break ;
		}
		aux[file_data] = '\0';
		buf = ft_strjoin(buf, aux);
	}
	if (file_data > 0)
		free(aux);
	return (buf);
}

static char	*check_read(char *buf)
{
	if (buf == NULL || buf[0] == '\0')
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

/*
	-----------------Strjoin----------------
	To join both strings y one new string,
		freezing the first one
*/

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1)
	{
		str = (char *) malloc((ft_strlen(s2) + 1) * sizeof(char));
		ft_strlcpy(str, s2, (ft_strlen(s2) + 1));
		free(s1);
		return (str);
	}
	s1_len = (size_t)ft_strlen((char *)s1);
	s2_len = (size_t)ft_strlen((char *)s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s1 == NULL || s2 == NULL || str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(&str[s1_len], s2, s2_len + 1);
	free(s1);
	return (str);
}

/*
	-----------------Substr----------------
	Return a new string (malloc) with the information
		of the string "s" since "s[start]" while len
*/

static char	*ft_substr(char *s, unsigned int start, size_t len)
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

/* int	main(void)
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
	// re = get_next_line(fd);
	// printf("3:%s", re);
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("4:%s", (re));
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("5:%s", (re));
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("6:%s", (re));
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("7:%s", (re));
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("8:%s", (re));
	// printf("................\n");
	// re = get_next_line(fd);
	// printf("9:%s", (re));
	// printf("................\n");
	free(re);
	close(fd);
} */
