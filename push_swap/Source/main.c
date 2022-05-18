/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:15:50 by odursun           #+#    #+#             */
/*   Updated: 2022/05/06 18:53:51 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;

	a.stack = 'a';
	b.stack = 'b';
	if (argc == 2)
		two_args(argv[1], &a, &b);
	else if (argc > 2)
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
