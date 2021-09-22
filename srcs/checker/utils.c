/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:51:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/22 19:04:18 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	return_error(int index)
{
	if (!index)
		ft_putstr_fd("Malloc error\n", 1);
	if (index == 1)
		ft_putstr_fd("Wrong argument\n", 1);
	if (index == 2)
		ft_putstr_fd("Duplicate argument\n", 1);
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

static void	norm_loop(t_stack **a, t_stack **b)
{
	int	space;

	space = 7;
	if (*a)
		space -= ft_intlen((*a)->num);
	write(1, "       ", space);
	if (*a)
		ft_putnbr_fd((*a)->num, 1);
	write(1, "|", 1);
	if (*b)
		ft_putnbr_fd((*b)->num, 1);
	write(1, "\n", 1);
	if (*a)
		*a = (*a)->next;
	if (*b)
		*b = (*b)->next;
}

void	print_lst(t_stack *a, t_stack *b)
{
	lst_rewind(&a);
	lst_rewind(&b);
	write(1, "   A   -   B   \n", 16);
	while (a || b)
		norm_loop(&a, &b);
}
