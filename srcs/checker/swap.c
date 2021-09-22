/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:55:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/22 18:21:46 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sa(t_stack **a)
{
	int	tmp;

	lst_rewind(a);
	if ((*a)->next)
	{
		tmp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
	}
}

void	sb(t_stack **b)
{
	int	tmp;

	lst_rewind(b);
	if ((*b)->next)
	{
		tmp = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = tmp;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp;

	lst_rewind(a);
	if ((*a)->next)
	{
		tmp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
	}
	lst_rewind(b);
	if ((*b)->next)
	{
		tmp = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = tmp;
	}
}
