/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:30:46 by odursun           #+#    #+#             */
/*   Updated: 2022/04/10 17:17:48 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	three_args(t_swap *a, t_swap *b)
{
	if (a->array[a->size - 1] == 0)
	{
		if (a->array[a->size - 2] == 2)
		{
			push(a, b, 0);
			if (a->array[a->size - 1] > a->array[a->size - 2])
				swap(a, 0);
			push(b, a, 0);
		}
	}
	else if (a->array[a->size - 2] == 0)
	{
		if (a->array[a->size - 1] == 2)
			rotate(a, 0);
		else if (a->array[a->size - 1] == 1)
			swap(a, 0);
	}
	else if (a->array[a->size - 3] == 0)
	{
		if (a->array[a->size - 1] > a->array[a->size - 2])
			swap(a, 0);
		rev_rotate(a, 0);
	}
}

void	four_args(t_swap *a, t_swap *b)
{
	int	i;

	i = 0;
	if (a->size == 4)
	{
		while (a->array[i] != 3)
			i++;
		if (i == 0)
			rev_rotate(a, 0);
		else
			while (++i < a->size)
				rotate(a, 0);
		push(a, b, 0);
		three_args(a, b);
		push(b, a, 0);
		rotate(a, 0);
	}
	else
	{
		if (b->array[b->size - 1] > b->array[b->size - 2])
			swap(b, 0);
		three_args(a, b);
		push(b, a, 0);
		rotate(a, 0);
	}
}

void	five_args(t_swap *a, t_swap *b, int i)
{
	if (i < 2)
	{
		while (--i >= 0)
		{
			rev_rotate(a, 0);
			if (a->array[a->size - 1] == 3)
				push(a, b, 0);
		}
	}
	else
	{
		while (i++ < a->size)
		{
			rotate(a, 0);
			if (a->array[a->size - 1] == 3)
				push(a, b, 0);
		}
	}
}

void	five_arg(t_swap *a, t_swap *b)
{
	int	i;

	i = 0;
	if (a->array[a->size - 1] == 3)
		push(a, b, 0);
	while (a->array[i] != 4)
		i++;
	i++;
	five_args(a, b, i);
	push(a, b, 0);
	four_args(a, b);
	push(b, a, 0);
	rotate(a, 0);
}

void	smaller_list(t_swap *a, t_swap *b)
{
	if (a->size == 2)
	{
		if (a->array[a->size - 1] > a->array[a->size - 2])
			swap(a, 0);
	}
	else if (a->size == 3)
		three_args(a, b);
	else if (a->size == 4)
		four_args(a, b);
	else if (a->size == 5)
		five_arg(a, b);
}
