/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:05 by odursun           #+#    #+#             */
/*   Updated: 2022/02/06 15:53:20 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_contorller(char input_str, va_list *parm)
{
	int	top;

	top = 0;
	if (input_str == 'c')
		top += ft_putchar(va_arg(*parm, int));
	if (input_str == '%')
		top += write(1, "%", 1);
	else if (input_str == 's')
		top += ft_putstr(va_arg(*parm, char *));
	else if (input_str == 'p')
	{
		top += write(1, "0x", 2);
		ft_pointer(va_arg(*parm, unsigned long), &top);
	}
	else if (input_str == 'd' || input_str == 'i')
		ft_putnbr(va_arg(*parm, int), &top);
	else if (input_str == 'u')
		ft_uns(va_arg(*parm, unsigned int), &top);
	else if (input_str == 'x')
		ft_hexconvert_low(va_arg(*parm, unsigned int), &top);
	else if (input_str == 'X')
		ft_hexconvert_up(va_arg(*parm, unsigned int), &top);
	return (top);
}

int	ft_printf(const char *str, ...)
{
	int		top;
	va_list	parm;

	va_start(parm, str);
	top = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			top += ft_contorller(*str, &parm);
		}
		else
			top += ft_putchar(*str);
		str++;
	}
	va_end(parm);
	return (top);
}
/*
int main()
{
	int x;
	x = 50;
	int *pointer = &x;
	ft_printf("MYYYYY\n\nString: %s\nChar: %c\n Unsigned: %u\nPointer: %p\n \
	D. Integer: %d \
	\nInteger: %i\n", "My String", 'c', -214783648, pointer, 214783647, 214783647);
	printf("\nString: %s\nChar: %c\n Unsigned: %u\nPointer: %p\nD. Integer: %d \
	\nInteger: %i \
	\n", "My String", 'c', -214783648, pointer, 214783647, 214783647);
	return (0);
}*/