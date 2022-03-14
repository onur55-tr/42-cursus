/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:59:25 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 17:33:43 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	free_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
		mlx_destroy_image(game->mlx_ptr, game->imgs[i++]);
}

void	free_buff(t_game *game)
{
	free(game->bf);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

void	*free_last(t_game *game)
{
	free_map(game);
	free_buff(game);
	free_imgs(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_FAILURE);
	return (0);
}
