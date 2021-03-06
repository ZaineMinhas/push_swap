/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:07:46 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/23 17:50:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	lst_rewind(a);
	tmp = *a;
	(*a)->next->prev = NULL;
	lst_forward(a);
	tmp->prev = *a;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	lst_rewind(b);
	tmp = *b;
	(*b)->next->prev = NULL;
	lst_forward(b);
	tmp->prev = *b;
	(*b)->next = tmp;
	(*b)->next->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		lst_rewind(a);
		tmp = *a;
		(*a)->next->prev = NULL;
		lst_forward(a);
		tmp->prev = *a;
		(*a)->next = tmp;
		(*a)->next->next = NULL;
	}
	if (*b)
	{
		lst_rewind(b);
		tmp = *b;
		(*b)->next->prev = NULL;
		lst_forward(b);
		tmp->prev = *b;
		(*b)->next = tmp;
		(*b)->next->next = NULL;
	}
	ft_putendl_fd("rr", 1);
}
