/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:51:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:45:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	return_error(t_var *var, int index)
{
	if (index == 1)
		ft_putstr_fd("Error\n", 1);
	else if (index == 2)
		ft_putstr_fd("KO\n", 1);
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
	system("clear");
	write(1, "   A   -   B   \n", 16);
	while (a || b)
		norm_loop(&a, &b);
}
