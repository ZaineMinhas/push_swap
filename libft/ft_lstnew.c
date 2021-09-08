/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:00:26 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:13:47 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	dest = (t_list *)malloc(sizeof(t_list));
	if (!dest)
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}
