/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:07:19 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/20 19:14:17 by zminhas          ###   ########.fr       */
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

void	print_lst(t_stack *a, t_stack *b)
{
	//system("clear");
	lst_rewind(&a);
	lst_rewind(&b);
	write(1, "   A   -   B   \n", 16);
	while (a || b)
		norm_loop(&a, &b);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 1)
		return (1);
	read_args(argc, argv, &var);
	if (!sorted(&var.a))
		sort(&var);
	print_lst(var.a, var.b);
}

//la commande  : make && make clean && ./push_swap 1 2 3 7 8 14 19 20 4 16 9 5 18 17 13 6 10 11 12