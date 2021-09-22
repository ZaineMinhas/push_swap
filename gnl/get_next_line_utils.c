/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:16:55 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/19 16:27:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_protect(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;

	if (!src && !dest)
		return (dest);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	while (n-- > 0)
		dest2[n] = src2[n];
	return ((void *)dest2);
}

char	*ft_gnljoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = -1;
	size = ft_strlen_protect(s1) + ft_strlen_protect(s2) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	while (++i < size)
		dest[i] = 0;
	if (!dest)
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen_protect(s1));
	ft_memcpy(dest + ft_strlen_protect(s1), s2, ft_strlen_protect(s2));
	free((void *)s1);
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	size = ft_strlen_protect(s1) + 1;
	i = -1;
	dest = (char *)malloc(sizeof(char) * (size));
	while (++i < size)
		dest[i] = 0;
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	return (dest);
}

char	*ft_strchr_dup_remix(const char *s, int c)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
		{
			dest = ft_strdup((char *)(s + i + 1));
			free((void *)s);
			return (dest);
		}
	}
	free((void *)s);
	return (NULL);
}
