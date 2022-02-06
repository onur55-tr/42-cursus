/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:47:12 by odursun           #+#    #+#             */
/*   Updated: 2022/02/06 15:06:29 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int *s)
{
	if (n == -2147483648)
	{
		*s += ft_putstr("-2147483648");
		return (*s);
	}
	if (n < 0)
	{
		*s += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, s);
		ft_putnbr(n % 10, s);
	}
	if (n >= 0 && n < 10)
		*s += ft_putchar(n + 48);
	return (*s);
}

int	ft_pointer(unsigned long num, int *s)
{
	if (num < 16)
	{
		if (num < 10)
			*s += ft_putchar(num + 48);
		else
			*s += ft_putchar(num + 87);
	}
	else
	{
		ft_pointer(num / 16, s);
		ft_pointer(num % 16, s);
	}
	return (*s);
}

int	ft_uns(unsigned int number, int *s)
{

	if (number >= 0 && number <= 9)
		*s += ft_putchar(number + 48);
	if (number > 9)
	{
		ft_uns(number / 10, s);
		ft_uns(number % 10, s);
	}
	return (*s);
}
