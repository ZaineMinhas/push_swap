/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:50:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/29 15:08:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	atoi_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	long long	nb;
	long long	nb_tmp;
	int			pos_neg;
	int			i;

	i = 0;
	pos_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos_neg = -1;
	if (!ft_isdigit(str[i]))
		atoi_error();
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb_tmp = nb;
		nb = nb * 10 + (str[i++] - 48);
		if (nb < nb_tmp || (pos_neg == 1 && nb > INT_MAX))
			atoi_error();
		else if (pos_neg == -1 && (nb * pos_neg) < (long long)INT_MIN)
			atoi_error();
	}
	return ((int)nb * pos_neg);
}
