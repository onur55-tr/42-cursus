/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:37:49 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 17:33:23 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_error(char *message)
{
	ft_printf("\033[0;31m\t %s\n\033[0m", message);
	exit(EXIT_FAILURE);
}

void	malloc_error(int fd, char *message)
{
	ft_printf("\033[0;31mError\n\t   %s\n\033[0m", message);
	close (fd);
	exit(EXIT_FAILURE);
}

void	split_error(t_game *game)
{
	ft_printf("Error\n Bölme Hatası.");
	free(game->bf);
	exit(1);
}

void	map_err(t_game *game, char sgn_err)
{
	int	i;

	i = 0;
	if (sgn_err == '0')
		ft_error("Sutun Hatası.");
	else if (sgn_err == '1')
		ft_error("Duvar Hatası.");
	else if (sgn_err == '2')
		ft_error("Bilinmeyen Karakter Hatası.");
	else if (sgn_err == '3')
		ft_error("Dikdörtgen Hatası.");
	else if (sgn_err == '4')
		ft_error("IMG Malloc Error.");
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	free(game->bf);
	exit(1);
}
