/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:53:45 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/28 18:12:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
