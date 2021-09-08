/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:38:45 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:14:54 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_bis;
	unsigned const char	*s2_bis;
	size_t				i;

	i = -1;
	s1_bis = (unsigned const char *)s1;
	s2_bis = (unsigned const char *)s2;
	while (++i < n)
		if (!(s1_bis[i] == s2_bis[i]))
			return (s1_bis[i] - s2_bis[i]);
	return (0);
}
