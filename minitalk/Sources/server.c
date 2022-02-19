/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:06:02 by odursun           #+#    #+#             */
/*   Updated: 2022/02/16 13:49:33 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

void	server_receive(int binary)
{
	static int					bit = 0;
	static unsigned char		letter = 0;

	letter += ((binary & 1) << bit++);
	if (bit == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		letter = 0;
		bit = 0;
	}
	return ;
}

void	server_loop(t_list *talk)
{
	while (42)
	{
		if ((signal(SIGUSR1, server_receive) == SIG_ERR)
			|| (signal(SIGUSR2, server_receive) == SIG_ERR))
		{
			ft_putstr("[1;31m[ERROR]: SIGNAL ERROR!!!\n\e[0m");
			free(talk);
			talk = NULL;
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_list	*talk;

	(void)av;
	talk = NULL;
	if (ac != 1)
	{
		ft_putstr("\e[1;31m[ERROR]: ./server sadece 1 argüman.\n\e[0m");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = malloc(sizeof(t_list));
		if (!talk)
			exit(EXIT_FAILURE);
		talk->pid_server = getpid();
		ft_putstr("\e[1;32m[SUCCESS]\e[0m\n\e[0;31mServer ready!\nPID: \e[0m");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	talk = NULL;
	return (0);
}
