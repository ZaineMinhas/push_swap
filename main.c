/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:07:19 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/13 20:36:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	print_lst(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	system("clear");
	lst_rewind(a);
	lst_rewind(b);
	tmp_a = *a;
	tmp_b = *b;
	write(1, "   A   -   B   \n", 16);
	while (*a || *b)
		norm_loop(a, b);
	*a = tmp_a;
	*b = tmp_b;
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 1)
		return (1);
	read_args(argc, argv, &var);
	print_lst(&var.a, &var.b);
	if (!sorted(&var.a))
		sort(&var);
	print_lst(&var.a, &var.b);
}
