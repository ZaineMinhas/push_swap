/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:40 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/11 14:35:15 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_var(t_var *var)
{
	var->b = malloc(sizeof(t_stack));
	if (!var->b)
		exit(1);
	var->b->next = NULL;
	var->b->prev = NULL;
}
