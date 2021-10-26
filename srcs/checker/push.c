/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:43:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:51:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	del_top(t_stack **old)
{
	lst_rewind(old);
	if (*old)
	{
		if (!(*old)->next)
		{
			free(*old);
			*old = NULL;
		}
		else
		{
			*old = (*old)->next;
			free((*old)->prev);
			(*old)->prev = NULL;
		}
	}
}

static void	add_top(t_var *var, t_stack **new, int num)
{
	t_stack	*elem;

	if (*new)
	{
		elem = malloc(sizeof(t_stack));
		if (!elem)
			return_error(var, 0);
		elem->next = *new;
		elem->prev = NULL;
		elem->num = num;
		(*new)->prev = elem;
		*new = (*new)->prev;
	}
	else
	{
		*new = malloc(sizeof(t_stack));
		if (!*new)
			return_error(var, 0);
		(*new)->next = NULL;
		(*new)->prev = NULL;
		(*new)->num = num;
	}
}

void	pa(t_var *var, t_stack **b, t_stack **a)
{
	int	tmp;

	if (!*b)
		return_error(var, 2);
	lst_rewind(a);
	lst_rewind(b);
	tmp = (*b)->num;
	del_top(b);
	add_top(var, a, tmp);
	lst_rewind(a);
	lst_rewind(b);
}

void	pb(t_var *var, t_stack **a, t_stack **b)
{
	int	tmp;

	if (!*a)
		return_error(var, 2);
	lst_rewind(a);
	lst_rewind(b);
	tmp = (*a)->num;
	del_top(a);
	add_top(var, b, tmp);
	lst_rewind(a);
	lst_rewind(b);
}
