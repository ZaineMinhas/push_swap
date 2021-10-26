/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:07:46 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:53:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ra(t_var *var, t_stack **a)
{
	t_stack	*tmp;

	if (lstlen(*a) < 2)
		return_error(var, 2);
	lst_rewind(a);
	tmp = *a;
	(*a)->next->prev = NULL;
	lst_forward(a);
	tmp->prev = *a;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
}

void	rb(t_var *var, t_stack **b)
{
	t_stack	*tmp;

	if (lstlen(*b) < 2)
		return_error(var, 2);
	lst_rewind(b);
	tmp = *b;
	(*b)->next->prev = NULL;
	lst_forward(b);
	tmp->prev = *b;
	(*b)->next = tmp;
	(*b)->next->next = NULL;
}

void	rr(t_var *var, t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (lstlen(*a) < 2 || lstlen(*b) < 2)
		return_error(var, 2);
	lst_rewind(a);
	tmp = *a;
	(*a)->next->prev = NULL;
	lst_forward(a);
	tmp->prev = *a;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	lst_rewind(b);
	tmp = *b;
	(*b)->next->prev = NULL;
	lst_forward(b);
	tmp->prev = *b;
	(*b)->next = tmp;
	(*b)->next->next = NULL;
}
