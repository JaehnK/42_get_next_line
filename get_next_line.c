/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:23:47 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/21 14:13:18 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_text(int fd)
{
	int		f;
	int		idx;
	char	*bf;

	f = 0;
	idx = 0;
	bf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bf)
		return (NULL);
	while (!ft_check_newline(bf) && f >= 0)
	{
		f = read(fd, bf + idx, BUFFER_SIZE);
		bf = ft_gnl_strdup(bf, BUFFER_SIZE);
		idx += f;
//		printf("BF: %s\n", bf);
	}
	return (bf);
}

char	*get_ans(char *remain, char *buf)
{
	char	*ans;

	if (!remain && !buf)
		ans = ft_gnl_strjoin(remain, buf, 0, 0);
	if (!remain && buf)
		ans = ft_gnl_strjoin(remain, buf, 0, ft_strlen(buf, '\n'));
	if (remain && !buf)
		ans = ft_gnl_strjoin(remain, buf, ft_strlen(remain, '\n'), 0);
	if (remain && buf)
		ans = ft_gnl_strjoin(remain, buf, ft_strlen(remain, '\0'),\
				ft_strlen(buf, '\n'));
	return (ans);
}

char	*update_remain(char *remain, char *buf)
{
	char	*tmp;
	
	if (!buf)
		tmp = ft_updater(remain);
	else
		tmp = ft_updater(buf);
	free(buf);
	free(remain);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buf;
	char		*ans;

	if (!ft_check_newline(remain))
		buf = ft_read_text(fd);
	else
		buf = NULL;
	ans = get_ans(remain, buf);
	remain = update_remain(remain, buf);
	return (ans);
}
/*
int	main(void)
{
	int	fd;
	char *ptr;

	fd = open("./tests/1-brouette.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		ptr =get_next_line(fd);
		printf("PTR: %s", ptr);
		printf("\n--------------------\n");
		free(ptr);
	}
	close(fd);
	return (0);
}*/
