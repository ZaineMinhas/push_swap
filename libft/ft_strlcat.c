/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:07:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:18:35 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	i;

	if (!src || !dest)
		return (0);
	dest_len = ft_strlen(dest);
	if (dstsize <= dest_len)
		return (dstsize + ft_strlen(src));
	i = -1;
	while (src[++i] && i < dstsize - dest_len - 1)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = 0;
	return (dest_len + ft_strlen(src));
}
