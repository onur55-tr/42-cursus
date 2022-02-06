/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:54:16 by odursun           #+#    #+#             */
/*   Updated: 2022/02/06 13:46:12 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(int n, int *s);
int	ft_pointer(unsigned long num, int *s);
int	ft_uns(unsigned int number, int *s);
int	ft_printf(const char *str, ...);
int	ft_hexconvert_up(unsigned int hexu_input, int *s);
int	ft_hexconvert_low(unsigned int hexl_input, int *s);

#endif
