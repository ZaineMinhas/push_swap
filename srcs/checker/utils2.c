/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:51:44 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:44:21 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	lstlen(t_stack *lst)
{
	int	i;

	if (!(lst))
		return (0);
	i = 1;
	lst_rewind(&lst);
	while ((lst)->next)
	{
		lst = (lst)->next;
		i++;
	}
	return (i);
}

void	free_lst(t_stack **a, t_stack **b)
{
	lst_rewind(a);
	if (*a)
	{
		while ((*a)->next)
		{
			*a = (*a)->next;
			free((*a)->prev);
		}
		free(*a);
	}
	lst_rewind(b);
	if (*b)
	{
		while ((*b)->next)
		{
			*b = (*b)->next;
			free((*b)->prev);
		}
		free(*b);
	}
}
