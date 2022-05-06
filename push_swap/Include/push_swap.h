/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:16:19 by odursun           #+#    #+#             */
/*   Updated: 2022/04/11 11:59:07 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*# include <limits.h>*/
# include "../Printf/ft_printf.h"
# include "../Gnl/get_next_line.h"
# include "../Libft/libft.h"

typedef struct s_swap
{
	int	*array;
	int	size;
<<<<<<< HEAD
	int	stack;
=======
	int	type;
>>>>>>> 93a9c08c324acc54e8d16ede06f0b58fa5f58599
}	t_swap;

void	two_args(char *s, t_swap *a, t_swap *b);
void	free_func(t_swap *a, t_swap *b);
void	error_message(t_swap *a, t_swap *b);
void	more_args(int argc, char **argv, t_swap *a, t_swap *b);
void	check_double(t_swap *a, t_swap *b);
void	check_list(t_swap *a, t_swap *b);
int		number_count(char *s);
int		ft_atoim(char *str, t_swap *a, t_swap *b);
void	sort_path(t_swap *a, t_swap *b, int *i_a, int *i_b);
void	send_b(t_swap *a, t_swap *b);
void	smaller_list(t_swap *a, t_swap *b);
void	sort_list(t_swap *a, t_swap *b);
void	swap(t_swap *data, int control);
void	rotate(t_swap *data, int control);
void	push(t_swap *data, t_swap *data1);
void	rev_rotate(t_swap *data, int control);
void	rotate_together(t_swap *a, t_swap *b, int control);
void	rev_rotate_together(t_swap *a, t_swap *b, int control);
void	swap_together(t_swap *a, t_swap *b, int control);
<<<<<<< HEAD
void	indexing(t_swap *a);
int		*sort_before(t_swap *a);
=======
>>>>>>> 93a9c08c324acc54e8d16ede06f0b58fa5f58599
#endif
