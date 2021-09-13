/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:23:18 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/13 15:26:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_stack **a)
{
	t_stack	*tmp;

	lst_rewind(a);
	tmp = *a;
	while ((*a)->next)
	{
		if ((*a)->num > (*a)->next->num)
			return (0);
		*a = (*a)->next;
	}
	return (1);
}
