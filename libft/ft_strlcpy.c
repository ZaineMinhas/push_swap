/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:08:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:29:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src || !dest)
		return (0);
	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize)
	{
		while (src[i] && (i < dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (ft_strlen(src));
}
