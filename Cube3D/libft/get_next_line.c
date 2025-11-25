/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:46:25 by dfernan3          #+#    #+#             */
/*   Updated: 2025/02/26 16:21:24 by csalazar         ###   ########.fr       */
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
	int		i;

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
	static char	*tmp;
	char		*line;
	char		*tmp2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	tmp = read_txt(fd, tmp);
	line = ft_get_line(tmp);
	tmp2 = tmp;
	tmp = ft_unitrim(tmp);
	free(tmp2);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	
	fd = (open("texto.txt", O_RDONLY));
	if (fd < 0)
        return (0);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/
