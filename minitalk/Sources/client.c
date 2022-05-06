/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:06:12 by odursun           #+#    #+#             */
/*   Updated: 2022/03/26 19:45:00 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

void	ft_kill(t_list *pid)
{
	int		i;
	char	c;

	while (*pid->str)
	{
		i = 8;
		c = *pid->str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid->pid_server, SIGUSR1);
			else
				kill(pid->pid_server, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid->pid_server, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	t_list	talk;

	if (argc != 3)
	{
		ft_putstr("\e[1;31m[ERROR]: Use ./server sadece 3 argüman!!!\n\e[0m");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk.pid_server = ft_atoi(argv[1]);
		talk.str = argv[2];
		if (talk.pid_server <= 0)
		{
			ft_putstr("[\e[1;31m[ERROR]: PID is 0'a eşit veya küçük.\n\e[0m");
			exit(EXIT_FAILURE);
		}
		ft_kill(&talk);
	}
	return (0);
}
