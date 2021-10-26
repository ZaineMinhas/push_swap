/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:05:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 13:53:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_biggest(t_stack *lst)
{
	int	biggest;

	lst_rewind(&lst);
	biggest = lst->num;
	while (lst->next)
	{
		if (biggest < lst->next->num)
			biggest = lst->next->num;
		lst = lst->next;
	}
	return (biggest);
}

int	find_smallest(t_stack *lst)
{
	int	smallest;

	lst_rewind(&lst);
	smallest = lst->num;
	while (lst->next)
	{
		if (smallest > lst->next->num)
			smallest = lst->next->num;
		lst = lst->next;
	}
	return (smallest);
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
