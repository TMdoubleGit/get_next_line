/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:26 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/29 14:52:53 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		read_return;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_return = 1;
	while (!ft_strchr(stash, '\n') && read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free (buf);
			return (NULL);
		}
		*(buf + read_return) = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!*(stash + 0))
		return (NULL);
	while (*(stash + i) && *(stash + i) != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (*(stash + i) && *(stash + i) != '\n')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	if (*(stash + i) == '\n')
	{
		*(line + i) = '\n';
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

char	*ft_get_rol(char *stash)
{
	char	*nextstash;
	int		i;
	int		j;

	i = 0;
	while (*(stash + i) && *(stash + i) != '\n')
		i++;
	if (!*(stash + i))
	{
		free (stash);
		return (NULL);
	}
	nextstash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!nextstash)
	{
		free (stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (*(stash + i))
		*(nextstash + j++) = *(stash + i++);
	*(nextstash + j) = '\0';
	free (stash);
	return (nextstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_get_rol(stash);
	return (line);
}

// void	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 	{	
// 		write(1, "\0", 2);
// 		return ;
// 	}
// 	while (*(s + i))
// 	{
// 		write(1, &*(s + i), 1);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	int		fd = open("test.txt", O_RDONLY);
// 	int	i = 0;
// 	char *line;

// 	while (i < 30)
// 	{
// 		line = get_next_line(fd);
// 		ft_putstr(line);
// 		i++;
// 		free(line);
// 	}
// 	return (0);
// }