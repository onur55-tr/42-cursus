/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:52:34 by odursun           #+#    #+#             */
/*   Updated: 2022/06/02 19:28:13 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	*sort_before(t_swap *a)
{
	int	i;
	int	j;
	int	*tmp;
	int	tmp_alone;

	i = -1;
	tmp = malloc(sizeof(int) * a->size);
	while (++i < a->size)
		tmp[i] = a->array[i];
	i = -1;
	while (++i < a->size)
	{
		j = i - 1;
		while (++j < a->size)
		{
			if (tmp[i] > tmp[j])
			{
				tmp_alone = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = tmp_alone;
			}
		}
	}
	return (tmp);
}

void	indexing(t_swap *a)
{
	int	*sort;
	int	i;
	int	j;

	i = -1;
	sort = sort_before(a);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->array[i] == sort[j])
			{
				a->array[i] = j;
				break ;
			}
		}
	}
	free (sort);
}
