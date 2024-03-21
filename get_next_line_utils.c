/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/21 14:11:26 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] != c)
		idx++;
	return (idx);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2, int n1, int n2)
{
	char	*ans;
	int		i;

	i = 0;
	ans = (char *) malloc(sizeof(char) * (n1 + n2 + 1));
	if (!ans)
		return (NULL);
	while (s1 && i < n1)
		ans[i++] = *s1++;
	while (s2 && i < n1 + n2)
		ans[i++] = *s2++;
	ans[i] = '\0';
	return (ans);
}

char	*ft_gnl_strdup(char *s, int extra_size)
{
	size_t	len;
	size_t	idx;
	char	*res;

	idx = 0;
	len = ft_strlen(s, '\0');
	res = (char *) malloc(sizeof(char) * (len + extra_size + 1));
	if (!res)
		return (NULL);
	while (idx < len)
	{
		res[idx] = s[idx];
		idx++;
	}
	res[len + extra_size + 1] = '\0';
	free(s);
	return (res);
}

char	*ft_updater(char const *s)
{
	int		s_idx;
	int		update_idx;
	char	*update;

	s_idx = 0;
	update_idx = 0;
	while (*s != '\n')
		s++;
	s++;
	while (s[s_idx] != '\n' && s[s_idx] != '\0')
		s_idx++;
	update = (char *) malloc(sizeof(char) * (s_idx + 1));
	if (!update)
		return (NULL);
	while (update_idx < s_idx)
	{
		update[update_idx] = s[update_idx];
		update_idx++;
	}
	update[update_idx] = '\0';
	return (update);
}
