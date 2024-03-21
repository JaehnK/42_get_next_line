/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:24:27 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/21 14:12:03 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
//제출전 삭제하기
# include <fcntl.h>
# include <stdio.h>
char	*ft_updater(char const *s);
char	*ft_gnl_strdup(char *s, int extra_size);
char	*ft_gnl_strjoin(char const *s1, char const *s2, int n1, int n2);
size_t	ft_strlen(const char *s, char c);
char	*get_next_line(int fd);

#endif
