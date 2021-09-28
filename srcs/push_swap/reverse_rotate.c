/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:44:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/28 18:08:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	lst_forward(a);
	tmp = *a;
	(*a)->prev->next = NULL;
	lst_rewind(a);
	(*a)->prev = tmp;
	(*a)->prev->prev = NULL;
	(*a)->prev->next = *a;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	lst_forward(b);
	tmp = *b;
	(*b)->prev->next = NULL;
	lst_rewind(b);
	(*b)->prev = tmp;
	(*b)->prev->prev = NULL;
	(*b)->prev->next = *b;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		lst_forward(a);
		tmp = *a;
		(*a)->prev->next = NULL;
		lst_rewind(a);
		(*a)->prev = tmp;
		(*a)->prev->prev = NULL;
		(*a)->prev->next = *a;
	}
	if (*b)
	{
		lst_forward(b);
		tmp = *b;
		(*b)->prev->next = NULL;
		lst_rewind(b);
		(*b)->prev = tmp;
		(*b)->prev->prev = NULL;
		(*b)->prev->next = *b;
	}
	ft_putendl_fd("rrr", 1);
}
