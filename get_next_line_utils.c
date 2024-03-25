/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/25 22:23:04 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] != c && s[idx] != '\0')
		idx++;
	return (idx);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
		ptr[i++] = '\0';
	return ((void *) ptr);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	len1 = ft_strlen(s1, '\0');
	len2 = ft_strlen(s2, '\0');
	ans = (char *) ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!ans)
		return (NULL);
	while (s1 && i < len1)
		ans[i++] = *s1++;
	while (s2 && i < len1 + len2)
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
	res = (char *) ft_calloc(sizeof(char), (len + extra_size + 1));
	if (!res)
		return (NULL);
	while (idx < len)
	{
		res[idx] = s[idx];
		idx++;
	}
	while (idx < len + extra_size)
		res[idx++] = '\0';
	if (s)
		free(s);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *) ft_calloc(sizeof(char), len + 1);
	if (!s || !dest)
		return (NULL);
	while (i < len && start + i <= ft_strlen(s, '\0'))
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
