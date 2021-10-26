/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:53:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:36:15 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort3(t_stack **a)
{
	int	biggest;

	biggest = find_biggest(*a);
	lst_rewind(a);
	if ((*a)->num == biggest)
		ra(a);
	else if ((*a)->next->num == biggest)
		rra(a);
	lst_rewind(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

static void	sort4(t_var *var, t_stack **a, t_stack **b)
{
	int	small;

	small = find_smallest(*a);
	lst_rewind(a);
	if ((*a)->num == small)
		;
	else if ((*a)->next->num == small)
		sa(a);
	else if ((*a)->next->next->num == small)
	{
		rra(a);
		rra(a);
	}
	else
		rra(a);
	pb(var, a, b);
	sort3(a);
	pa(var, b, a);
}

static void	sort5(t_var *var, t_stack **a, t_stack **b)
{
	int	small;

	small = find_smallest(*a);
	lst_rewind(a);
	if ((*a)->num == small)
		;
	else if ((*a)->next->num == small)
		sa(a);
	else if ((*a)->next->next->num == small)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->num == small)
	{
		rra(a);
		rra(a);
	}
	else
		rra(a);
	pb(var, a, b);
	sort4(var, a, b);
	pa(var, b, a);
}

void	sort(t_var *var)
{
	if (lstlen(var->a) <= 5)
	{
		if (lstlen(var->a) == 2)
			sa(&var->a);
		else if (lstlen(var->a) == 3)
			sort3(&var->a);
		else if (lstlen(var->a) == 4)
			sort4(var, &var->a, &var->b);
		else if (lstlen(var->a) == 5)
			sort5(var, &var->a, &var->b);
	}
	else if (lstlen(var->a) <= 100)
		find_chunks(var, 5);
	else if (lstlen(var->a) <= 500)
		find_chunks(var, 10);
	else
		find_chunks(var, 15);
}
