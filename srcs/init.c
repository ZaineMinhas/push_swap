/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:40 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/10 18:30:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_var(t_var *var)
{
	var->a = malloc(sizeof(t_stack));
	var->b = malloc(sizeof(t_stack));
	if (!var->a || !var->b)
		exit(1);
}
