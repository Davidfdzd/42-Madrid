/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:41:01 by dfernan3          #+#    #+#             */
/*   Updated: 2024/10/18 11:56:33 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char				*ft_strchr(char *s, int c);
char				*ft_strtrim(char *s1);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s);
char				*get_next_line(int fd);

size_t				ft_strlen(char *str);

#endif