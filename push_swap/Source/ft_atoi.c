/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:51:47 by odursun           #+#    #+#             */
/*   Updated: 2022/04/14 14:02:23 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_atoim(char *s, t_swap *a, t_swap *b)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg *= -1;
		s++;
	}
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == ' '))
			error_message(a, b);
		if (*s == ' ' || *s == '\t')
			return ((int)res * neg);
		res = (res * 10) + *(s++) - '0';
		if (res > __INT_MAX__ || res < -__INT_MAX__ - 1)
			error_message(a, b);
	}
	return ((int)res * neg);
}
