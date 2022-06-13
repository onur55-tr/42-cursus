/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:34:57 by odursun           #+#    #+#             */
/*   Updated: 2022/04/14 14:00:22 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	make_pivot(t_swap *s)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = __INT_MAX__;
	max = -__INT_MAX__ - 1;
	while (i++ < s->size)
	{
		if (s->array[s->size - i] > max)
			max = s->array[s->size - i];
		if (s->array[s->size - i] < min)
			min = s->array[s->size - i];
	}
	return ((int)(max + min) / 2);
}

//bulduğu pivotun altındaki değer pushlayacak.
void	send_b(t_swap *a, t_swap *b)
{
	int	pivot;
	int	i;

	i = -1;
	pivot = make_pivot(a);
	if (a->size < 3)
		return ;
	while (++i < a->size)
	{
		if (a->array[a->size - 1] <= pivot)
			push(a, b, 0);
		else
			rotate(a, 0);
	}
	send_b(a, b);
}

//eğer b stackteki değer a'da yeri bulunmazsa en yüksek değeri geri dönderir.
int	max_value(t_swap *a)
{
	int	i;
	int	max;
	int	index;

	i = -1;
	max = -__INT_MAX__ - 1;
	while (++i < a->size)
	{
		if (a->array[i] > max)
		{
			max = a->array[i];
			index = i;
		}
	}
	return (index);
}

//b stackteki değerin a'daki en uygun index numarası
int	find_index(t_swap *a, int number)
{
	int	i;
	int	min;
	int	diff;
	int	index;

	i = -1;
	min = __INT_MAX__;
	index = -1;
	while (++i < a->size)
	{
		diff = a->array[a->size - 1 - i] - number;
		if (diff > 0 && diff < min)
		{
			min = diff;
			index = i;
		}
	}
	if (index == -1)
		index = max_value(a);
	return (index);
}

/*
 * en kısa yolu bulan func, b'deki her değer için a'daki yollar
 * hesaplanır takibinde en kısası işlem görür.
 */
void	sort_path(t_swap *a, t_swap *b, int *i_a, int *i_b)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = __INT_MAX__;
	m = -1;
	while (++m < b->size)
	{
		n = find_index(a, b->array[b->size - 1 - m]);
		if (m < b->size / 2)
			tmp[0] = m;
		else
			tmp[0] = b->size - 1 - m;
		if (n < a->size / 2)
			tmp[1] = n;
		else
			tmp[1] = a->size - 1 - n;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i_b = m;
			*i_a = n;
		}
	}
}
