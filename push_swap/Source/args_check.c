/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:29:29 by odursun           #+#    #+#             */
/*   Updated: 2022/04/14 14:00:01 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//kaç tane argüman varsa onu sayma
int	number_count(char *s, t_swap *a, t_swap *b)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			count++;
		else
			error_message(a, b);
		while ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			s++;
	}
	return (count);
}

/* 2 tane argüman gelme durumu ex:a.out "..." */
void	two_args(char *s, t_swap *a, t_swap *b)
{
	int	i;
	int	i_number;

	i_number = 0;
	i = 0;
	a->size = number_count(s, a, b);
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			a->array[a->size - 1 - i_number++] = ft_atoim(s, a, b);
		while ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			s++;
	}
}

//argümanın 2 den fazla gelme durumu
void	more_args(int argc, char **argv, t_swap *a, t_swap *b)
{
	int	i;

	i = 0;
	a->size = argc - 1;
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	while (++i < argc)
	a->array[a->size - i] = ft_atoim(argv[i], a, b);
}

//çift sayı kontrolü
void	check_double(t_swap *a, t_swap *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i;
		while (j < a->size - 1)
			if (a->array[i] == a->array[j++ + 1])
				error_message(a, b);
		i++;
	}
}

//sıralı mı değil mi
void	check_list(t_swap *a, t_swap *b)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
		{
			counter = 0;
			break ;
		}
		i++;
	}
	if (counter == 1)
		free_func(a, b);
}