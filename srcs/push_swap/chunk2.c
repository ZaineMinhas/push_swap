/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:23:12 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/19 19:30:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*static int	sort_stack_a2()
{
	int	i;
	int	j;

	i = 0;
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
	return (i);
}*/

void	sort_stack_a(t_var *var, int biggest)
{
	int	i;
	int	j;

	lst_rewind(&var->b);
	i = find_first_big_b(var, biggest);
	j = find_last_big_b(var, biggest);
	if (i < j)
	{
		j = 0;
		while (++j < i + 1)
			rb(&var->b);
	}
	else
	{
		i = -1;
		while (++i < j)
			rrb(&var->b);
	}
	pa(&var->b, &var->a);
}
