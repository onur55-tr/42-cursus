/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:52:34 by odursun           #+#    #+#             */
/*   Updated: 2022/05/06 18:52:35 by odursun          ###   ########.fr       */
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

	i = 0;
	sort = sort_before(a);
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == sort[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free (sort);
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
