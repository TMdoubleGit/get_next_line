/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:01:03 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/29 12:53:43 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_get_rol(char *stash);
char	*ft_get_line(char *stash);
char	*ft_read(int fd, char *stash);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif