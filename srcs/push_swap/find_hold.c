/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:40:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/21 15:55:29 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_hold_first_a(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_rewind(&var->a);
	while (var->a->next)
	{
		if (var->a->num >= min && var->a->num <= max)
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

int	find_hold_last_a(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_forward(&var->a);
	while (var->a->prev)
	{
		if (var->a->num >= min && var->a->num <= max)
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

int	find_first_big_b(t_var *var, int big)
{
	int	i;

	i = 0;
	lst_rewind(&var->b);
	while (var->b->next)
	{
		if (var->b->num == big)
			break ;
		i++;
		var->b = var->b->next;
	}
	return (i);
}

int	find_last_big_b(t_var *var, int big)
{
	int	i;

	i = 0;
	lst_forward(&var->b);
	while (var->b->prev)
	{
		if (var->b->num == big)
		{
			var->hold_last = var->b->num;
			break ;
		}
		i++;
		var->b = var->b->prev;
	}
	lst_rewind(&var->b);
	return (++i);
}
