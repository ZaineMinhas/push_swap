/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:23:12 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/21 17:17:02 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	lift_up(t_var *var, int i, int j, int big)
{
	j = 0;
	while (++j < i + 1)
	{
		rb(&var->b);
		lst_rewind(&var->b);
		if (var->b->num == big)
		{
			var->bool = 1;
			break ;
		}
	}
}

static void	lift_down(t_var *var, int i, int j, int big)
{
	i = -1;
	while (++i < j)
	{
		rrb(&var->b);
		lst_rewind(&var->b);
		if (var->b->num == big)
		{
			var->bool = 1;
			break ;
		}
	}
}

void	sort_stack_a(t_var *var, int biggest, int almost_biggest)
{
	int	i;
	int	j;

	lst_rewind(&var->b);
	i = find_first_big_b(var, biggest);
	j = find_last_big_b(var, biggest);
	if (i < j)
		lift_up(var, i, j, almost_biggest);
	else
		lift_down(var, i, j, almost_biggest);
	pa(&var->b, &var->a);
}
