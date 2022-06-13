/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:08:46 by odursun           #+#    #+#             */
/*   Updated: 2022/04/07 15:10:43 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	free_func(t_swap *a, t_swap *b)
{
	free(a->array);
	free(b->array);
	exit(1);
}

void	error_message(t_swap *a, t_swap *b)
{
	write(2, "Error\n", 6);
	free_func(a, b);
}
