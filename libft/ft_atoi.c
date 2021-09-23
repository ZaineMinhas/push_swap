/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:50:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/23 18:23:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;
	int						i;

	i = 0;
	pos_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos_neg = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb_tmp = nb;
		nb = nb * 10 + (str[i++] - 48);
		if (nb < nb_tmp || nb > LLONG_MAX)
		{
			ft_putendl_fd("Error", 1);
			exit(1);
		}
	}
	return ((int)nb * pos_neg);
}
