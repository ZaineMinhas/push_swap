/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:15:07 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/18 17:13:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*elemf;

	if (!lst || !f)
		return (NULL);
	dest = NULL;
	while (lst)
	{
		elemf = ft_lstnew(f(lst->content));
		if (!elemf)
		{
			if (del)
				ft_lstclear(&elemf, del);
			else
				ft_free(&dest);
			return (NULL);
		}
		ft_lstadd_back(&dest, elemf);
		lst = lst->next;
	}
	return (dest);
}
