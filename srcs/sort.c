/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:53:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/13 20:36:03 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort3(t_stack **a)
{
	int	biggest;

	biggest = find_biggest(a);
	lst_rewind(a);
	if ((*a)->num == biggest)
		ra(a);
	else
	{
		*a = (*a)->next;
		if ((*a)->num == biggest)
			rra(a);
	}
	lst_rewind(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	sort(t_var *var)
{
	if (lstlen(&var->a) <= 5)
	{
		if (lstlen(&var->a) == 2)
			sa(&var->a);
		if (lstlen(&var->a) == 3)
			sort3(&var->a);
	}
}
