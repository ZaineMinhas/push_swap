/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:07:19 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/11 18:51:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 1)
		return (1);
	init_var(&var);
	read_args(argc, argv, &var);
	//print_lst(&var.a);
	return (0);
}
