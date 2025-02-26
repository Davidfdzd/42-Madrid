/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:41:32 by dfernan3          #+#    #+#             */
/*   Updated: 2024/11/28 15:07:27 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_g(char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return (s);
	return (NULL);
}

char	*ft_get_line(char *tmp)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!tmp || !*tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = ft_substr(tmp, 0, i);
	return (line);
}

char	*get_buffer(int fd)
{
	char	*buffer;
	ssize_t	i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*read_txt(int fd, char *tmp)
{
	char	*buffer;
	char	*tmp2;
	int		i;

	i = 1;
	while (!ft_strchr(tmp, '\n') && i > 0)
	{
		buffer = get_buffer(fd);
		if (!buffer)
		{
			free(tmp);
			return (NULL);
		}
		i = ft_strlen(buffer);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, buffer);
		free(tmp2);
		free(buffer);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*line;
	char		*tmp2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	tmp[fd] = read_txt(fd, tmp[fd]);
	line = ft_get_line(tmp[fd]);
	tmp2 = tmp[fd];
	tmp[fd] = ft_unitrim(tmp[fd]);
	free(tmp2);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd1;
	char	*line1;
	char	*line2;

	fd = open("quijote.txt", O_RDONLY);
	fd1 = open("texto.txt", O_RDONLY);
	if (fd < 0 || fd1 < 0)
		return (0);
	line1 = get_next_line(fd);
	line2 = get_next_line(fd1);
	while (line1 || line2)
	{
		if (line1)
		{
			printf("Archivo 1: %s", line1);
			free(line1);
			line1 = get_next_line(fd);
		}
		if (line2)
		{
			printf("Archivo 2: %s", line2);
			free(line2);
			line2 = get_next_line(fd1);
		}
	}
	close(fd);
	close(fd1);
}
*/
