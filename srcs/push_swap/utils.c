/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:51:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/29 15:05:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	return_error(t_var *var, int index)
{
	if (!index)
		ft_putstr_fd("Error\n", 1);
	if (index == 1)
		ft_putstr_fd("Error\n", 1);
	if (index == 2)
		ft_putstr_fd("Error\n", 1);
	free_lst(&var->a, &var->b);
	exit(1);
}

void	lst_rewind(t_stack **lst)
{
	if (*lst)
		while ((*lst)->prev)
			*lst = (*lst)->prev;
}

void	lst_forward(t_stack **lst)
{
	if (*lst)
		while ((*lst)->next)
			*lst = (*lst)->next;
}

int	lstlen(t_stack *lst)
{
	int	i;

	if (!(lst))
		return (0);
	i = 1;
	lst_rewind(&lst);
	while ((lst)->next)
	{
		lst = (lst)->next;
		i++;
	}
	return (i);
}

int	sorted(t_stack **a)
{
	lst_rewind(a);
	while ((*a)->next)
	{
		if ((*a)->num > (*a)->next->num)
			return (0);
		*a = (*a)->next;
	}
	return (1);
}
