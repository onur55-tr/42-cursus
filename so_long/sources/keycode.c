/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:03:28 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 17:09:27 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	*finish(t_game *game)
{
	finish_game(game);
	return (0);
}

int	key_a(t_game *game)
{
	if (game->bf[game->idx - 1] == 'C')
			game->score++;
	else if (game->bf[game->idx - 1] == 'E')
	{
		finish_game(game);
		return (0);
	}
	game->char_pos = game->imgs[3];
	game->bf[game->idx - 1] = 'P';
	game->bf[game->idx] = '0';
	ft_printf("Total Moves: %d\n", ++game->total_moves);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	replace_map(game);
	return (0);
}

int	key_s(t_game *game)
{
	if (game->bf[game->idx + game->x + 1] == 'C')
			game->score++;
	else if (game->bf[game->idx + game->x + 1] == 'E')
	{
		finish_game(game);
		return (0);
	}
	game->char_pos = game->imgs[1];
	game->bf[game->idx + game->x + 1] = 'P';
	game->bf[game->idx] = '0';
	ft_printf("Total Moves: %d\n", ++game->total_moves);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	replace_map(game);
	return (0);
}

int	key_d(t_game *game)
{
	if (game->bf[game->idx + 1] == 'C')
		game->score++;
	else if (game->bf[game->idx + 1] == 'E')
	{
		finish_game(game);
		return (0);
	}
	game->char_pos = game->imgs[2];
	game->bf[game->idx + 1] = 'P';
	game->bf[game->idx] = '0';
	ft_printf("Total Moves: %d\n", ++game->total_moves);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	replace_map(game);
	return (0);
}

int	char_moves(int key, t_game *gm)
{
	if ((key == A || key == LEFT) && gm->bf[gm->idx - 1] != '1')
		key_a(gm);
	else if ((key == S || key == DOWN) && gm->bf[gm->idx + gm->x + 1] != '1')
		key_s(gm);
	else if ((key == D || key == RIGHT) && gm->bf[gm->idx + 1] != '1')
		key_d(gm);
	else if ((key == W || key == UP) && gm->bf[gm->idx - gm->x - 1] != '1')
	{
		if (gm->bf[gm->idx - gm->x - 1] == 'C')
			gm->score++;
		else if (gm->bf[gm->idx - gm->x - 1] == 'E')
		{
			finish_game(gm);
			return (0);
		}
		gm->char_pos = gm->imgs[4];
		gm->bf[gm->idx - gm->x - 1] = 'P';
		gm->bf[gm->idx] = '0';
		ft_printf("Total Moves: %d\n", ++gm->total_moves);
	}
	else if (key == 53)
		exit(EXIT_FAILURE);
	mlx_clear_window(gm->mlx_ptr, gm->win_ptr);
	replace_map(gm);
	return (0);
}
