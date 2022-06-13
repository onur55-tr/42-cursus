/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:53:50 by odursun           #+#    #+#             */
/*   Updated: 2022/06/09 18:31:04 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	swap(t_swap *data, int control)
{
	int	tmp;

	if (data->size < 2)
		ft_printf("no number to swap");
	tmp = data->array[data->size - 1];
	data->array[data->size - 1] = data->array[data->size - 2];
	data->array[data->size - 2] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	rotate(t_swap *data, int control)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->array[data->size - 1];
	while (++i < data->size - 1)
		data->array[data->size - 1 - i] = data->array[data->size - 2 - i];
	data->array[0] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			ft_printf("ra\n");
		else if (data->stack == 'b')
			ft_printf("rb\n");
	}
}

void	push(t_swap *data, t_swap *data1, int control)
{
	if (data->size < 1)
		ft_printf("no number to push");
	data1->array[data1->size] = data->array[data->size - 1];
	data1->size += 1;
	data->size -= 1;
	if (!control)
	{
		if (data->stack == 'a')
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
}

void	rev_rotate(t_swap *data, int control)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->array[0];
	while (++i < data->size - 1)
		data->array[i] = data->array[i + 1];
	data->array[data->size - 1] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			ft_printf("rra\n");
		else if (data->stack == 'b')
			ft_printf("rrb\n");
	}
}
