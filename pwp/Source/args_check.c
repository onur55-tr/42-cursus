/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:29:29 by odursun           #+#    #+#             */
/*   Updated: 2022/06/08 18:17:49 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

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
		{
			if (a->array[i] == a->array[j++ + 1])
				error_message(a, b);
		}
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
	while (i < a->size)
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
