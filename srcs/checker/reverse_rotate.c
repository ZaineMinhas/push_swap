/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:44:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/22 18:21:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	lst_forward(a);
	tmp = *a;
	(*a)->prev->next = NULL;
	lst_rewind(a);
	(*a)->prev = tmp;
	(*a)->prev->prev = NULL;
	(*a)->prev->next = *a;
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	lst_forward(b);
	tmp = *b;
	(*b)->prev->next = NULL;
	lst_rewind(b);
	(*b)->prev = tmp;
	(*b)->prev->prev = NULL;
	(*b)->prev->next = *b;
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	lst_forward(a);
	tmp = *a;
	lst_rewind(a);
	(*a)->prev = tmp;
	(*a)->prev->prev = NULL;
	(*a)->prev->next = *a;
	lst_forward(b);
	tmp = *b;
	lst_rewind(b);
	(*b)->prev = tmp;
	(*b)->prev->prev = NULL;
	(*b)->prev->next = *b;
}
