/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:18:01 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:17:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	if (!c)
		return ((char *)(s + i));
	return (NULL);
}
