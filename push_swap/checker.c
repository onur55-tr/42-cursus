/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:32:23 by odursun           #+#    #+#             */
/*   Updated: 2022/05/06 18:50:17 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

//bonus
void	check_list_checker(int *control, t_swap *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}

void	rotate_func(char *s, t_swap *a, t_swap *b)
{
	if (s[0] == 'r' && s[1] == 'a')
		rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		rev_rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		rev_rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r')
		rotate_together(a, b, 1);
	else
		error_message(a, b);
}

void	make_pros(t_swap *a, t_swap *b, char *s)
{
	ft_printf(s);
	if (s[0] == 's' && s[1] == 'a')
		swap(a, 1);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b, 1);
	else if (s[0] == 's' && s[1] == 's')
		swap_together(a, b, 1);
	else if (s[0] == 'r')
		rotate_func(s[0], a, b);
	else if (s[0] == 'p' && s[1] == 'a')
		push(b, a);
	else if (s[0] == 'p' && s[1] == 'b')
		push(a, b);
	else
		error_message(a, b);
}

void	read_lines(t_swap *a, t_swap *b)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		make_pros(a, b, tmp);
	}
}

int	main(int ac, char **av)
{
	t_swap	a;
	t_swap	b;
	int		control;

	control = -1;
	a.stack = 'a';
	b.stack = 'b';
	if (ac == 2)
		two_args(av[1], &a, &b);
	else if (ac > 2 && ac <= 502)
		more_args(ac, av, &a, &b);
	else
		return (0);
	read_lines(&a, &b);
	check_list_checker(&control, &a);
	if (control == 1 && b.size == 0)
		ft_printf("OK");
	else if (!control || b.size != 0)
		ft_printf("KO");
}
