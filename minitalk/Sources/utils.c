/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:06:35 by odursun           #+#    #+#             */
/*   Updated: 2022/02/16 18:47:33 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

int	ft_strlen(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (str)
	{
		while (str[idx])
		{
			write(1, &str[idx], 1);
			idx++;
		}
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = (nbr % 10) + 48;
		write(1, &c, 1);
	}
}

int	ft_atoi(const char *str)
{
	long int	nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (nbr);
}
