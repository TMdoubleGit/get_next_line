/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:51:30 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/29 13:48:52 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (*(s2 + i))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*(s1 + 0) = '\0';
	}
	i = ft_strlen(s1);
	new = malloc(sizeof(char) * (i + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	j = 0;
	new = ft_strcpy(new, s1);
	while (*(s2 + j))
		*(new + i++) = *(s2 + j++);
	*(new + i) = '\0';
	free (s1);
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!c)
		return ((s + i));
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
