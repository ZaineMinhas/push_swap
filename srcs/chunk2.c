/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:23:12 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/20 19:02:44 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_hold_first(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_rewind(&var->a);
	while (var->a->next)
	{
		if (var->a->num <= max && var->a->num >= min)
		{
			var->hold_first = var->a->num;
			break ;
		}
		i++;
		var->a = var->a->next;
	}
	lst_rewind(&var->a);
	return (i);
}

int	find_hold_last(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_forward(&var->a);
	while (var->a->prev)
	{
		if (var->a->num <= max && var->a->num >= min)
		{
			var->hold_last = var->a->num;
			break ;
		}
		i++;
		var->a = var->a->prev;
	}
	lst_rewind(&var->a);
	return (++i);
}

int	sort_stack_b(t_stack **b, int num, int len)
{
	int	i;
	int	j;

	if (!*b || !(*b)->next)
		return (0);
	if (find_smallest(*b) > num)
		return (-1);
	else if (num > find_biggest(*b))
		return (0);
	i = 0;
	lst_rewind(b);
	while ((*b)->next && num < (*b)->num)
	{
		*b = (*b)->next;
		i++;
	}
	j = -1;
	if (i < len / 2)
		while (++j < i)
			rb(b);
	else
		while (++j < len - i)
			rrb(b);
	lst_rewind(b);
	return (i);
}
