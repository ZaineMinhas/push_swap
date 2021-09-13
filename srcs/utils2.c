/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:05:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/13 20:19:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_biggest(t_stack **lst)
{
	int	biggest;

	lst_rewind(lst);
	biggest = (*lst)->num;
	while ((*lst)->next)
	{
		if (biggest < (*lst)->next->num)
			biggest = (*lst)->next->num;
		*lst = (*lst)->next;
	}
	return (biggest);
}
