/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:55:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/23 17:52:09 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!*a)
		return ;
	lst_rewind(a);
	if ((*a)->next)
	{
		tmp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_stack **b)
{
	int	tmp;

	if (!*b)
		return ;
	lst_rewind(b);
	if ((*b)->next)
	{
		tmp = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = tmp;
		ft_putendl_fd("sb", 1);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp;

	lst_rewind(a);
	if (*a)
	{
		if ((*a)->next)
		{
			tmp = (*a)->num;
			(*a)->num = (*a)->next->num;
			(*a)->next->num = tmp;
		}
	}
	lst_rewind(b);
	if (*b)
	{
		if ((*b)->next)
		{
			tmp = (*b)->num;
			(*b)->num = (*b)->next->num;
			(*b)->next->num = tmp;
		}
	}
	ft_putendl_fd("ss", 1);
}
