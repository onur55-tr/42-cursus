/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:06:12 by odursun           #+#    #+#             */
/*   Updated: 2022/02/16 13:28:43 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

t_list	*client_initiate(void)
{
	t_list	*talk;

	talk = malloc(sizeof(t_list));
	if (!talk)
	{
		ft_putstr("\e[1;31m[ERROR]: Malloc() oluşturma hatası.\n\e[0m");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	return (talk);
}

void	client_send(t_list *talk, unsigned char *mess)
{
	int		idx;
	int		bit;
	int		signal;

	idx = -1;
	while (++idx <= ft_strlen((char *)mess))
	{
		bit = -1;
		signal = 0;
		while (++bit < 7)
		{
			if ((mess[idx] >> bit) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(100);
		}
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_list	*talk;

	talk = NULL;
	if (ac != 3)
	{
		ft_putstr("\e[1;31m[ERROR]: Use ./server sadece 3 argüman!!!\n\e[0m");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_initiate();
		talk->pid_server = ft_atoi(av[1]);
		if (talk->pid_server <= 0)
		{
			ft_putstr("[\e[1;31m[ERROR]: PID is 0'a eşit veya küçük.\n\e[0m");
			free(talk);
			talk = NULL;
			exit(EXIT_FAILURE);
		}
		client_send(talk, (unsigned char *)av[2]);
	}
	free(talk);
	talk = NULL;
	return (0);
}
