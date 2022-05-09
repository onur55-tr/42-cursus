/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_alignment_together.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:09:15 by odursun           #+#    #+#             */
/*   Updated: 2022/04/14 14:14:17 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	swap_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		swap(a, 1);
		swap(b, 1);
		ft_printf("ss\n");
	}
}

void	rotate_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		rotate(a, 1);
		rotate(b, 1);
		ft_printf("rr\n");
	}
}

void	rev_rotate_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		rev_rotate(a, 1);
		rev_rotate(b, 1);
		ft_printf("rrr\n");
	}
}
