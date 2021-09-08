/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:19:08 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/28 18:12:28 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned const char	*src2;
	unsigned char		*dest2;
	size_t				i;

	src2 = (unsigned const char *)src;
	dest2 = (unsigned char *)dest;
	i = -1;
	while (++i < n)
	{
		dest2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
