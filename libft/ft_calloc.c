/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:26:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:01:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*dest;

	dest = malloc(sizeof(void) * (size * count));
	if (!dest)
		return (NULL);
	ft_bzero(dest, (count * size));
	return (dest);
}
