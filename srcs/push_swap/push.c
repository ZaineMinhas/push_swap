/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:43:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:29:22 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

	if (*b)
	{
		lst_rewind(b);
		tmp = (*b)->num;
		del_top(b);
		add_top(var, a, tmp);
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_var *var, t_stack **a, t_stack **b)
{
	int	tmp;

	if (*a)
	{
		lst_rewind(a);
		tmp = (*a)->num;
		del_top(a);
		add_top(var, b, tmp);
		ft_putendl_fd("pb", 1);
	}
}
