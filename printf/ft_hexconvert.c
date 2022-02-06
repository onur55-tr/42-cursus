/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:53:54 by odursun           #+#    #+#             */
/*   Updated: 2022/02/06 13:38:02 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexconvert_up(unsigned int hexu_input, int *s)
{
	if (hexu_input < 16)
	{
		if (hexu_input < 10)
		{
			*s += ft_putchar(hexu_input + 48);
		}
		else
			*s += ft_putchar(hexu_input + 55);
	}
	else
	{
		ft_hexconvert_up(hexu_input / 16, s);
		ft_hexconvert_up(hexu_input % 16, s);
	}
	return (*s);
}

int	ft_hexconvert_low(unsigned int hexl_input, int *s)
{
	if (hexl_input < 16)
	{
		if (hexl_input < 10)
			*s += ft_putchar(hexl_input + 48);
		else
			*s += ft_putchar(hexl_input + 87);
	}
	else
	{
		ft_hexconvert_low(hexl_input / 16, s);
		ft_hexconvert_low(hexl_input % 16, s);
	}
	return (*s);
}
