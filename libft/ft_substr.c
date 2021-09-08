/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:10:36 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:26:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_good_size(size_t len, char const *s, unsigned int start)
{
	if (len > ft_strlen(s) - start + 1)
		return (ft_strlen(s) - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	len = ft_good_size(len, s, start);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s[start + (++i)] && len--)
		dest[i] = s[start + i];
	return (dest);
}
