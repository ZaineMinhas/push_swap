/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:19:49 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:15:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*src2;
	unsigned char		*dest2;
	size_t				i;

	if (!src && !dest)
		return (NULL);
	src2 = (unsigned const char *)src;
	dest2 = (unsigned char *)dest;
	if (dest2 <= src2)
	{
		i = -1;
		while (++i < n)
			dest2[i] = src2[i];
	}
	else
		while (n--)
			dest2[n] = src2[n];
	return (dest);
}
