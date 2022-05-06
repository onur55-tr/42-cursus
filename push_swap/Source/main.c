/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:15:50 by odursun           #+#    #+#             */
/*   Updated: 2022/04/11 11:46:52 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

<<<<<<< HEAD
=======
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

>>>>>>> 93a9c08c324acc54e8d16ede06f0b58fa5f58599
int	main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;

<<<<<<< HEAD
	a.stack = 'a';
	b.stack = 'b';
=======
	a.type = 'a';
	b.type = 'b';
>>>>>>> 93a9c08c324acc54e8d16ede06f0b58fa5f58599
	if (argc == 2)
		two_args(argv[1], &a, &b);
	else if (argc > 2 && argc <= 702)
		more_args(argc, argv, &a, &b);
	else
		return (0);
	check_double(&a, &b);
	indexing(&a);
	check_list(&a, &b);
	if (a.size > 5)
		sort_list(&a, &b);
	else
		smaller_list(&a, &b);
	free(a.array);
	free(b.array);
	return (0);
}
