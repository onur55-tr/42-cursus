/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:37:57 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 18:38:36 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	make_images(t_game *game)
{
	game->imgs = (void **)malloc(sizeof(void *) * 7);
	if (!game->imgs)
		map_err(game, '4');
	game->imgs[0] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/wall.xpm", &game->imgx, &game->imgy);
	game->imgs[1] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/on.xpm", &game->imgx, &game->imgy);
	game->imgs[2] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/sag.xpm", &game->imgx, &game->imgy);
	game->imgs[3] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/sol.xpm", &game->imgx, &game->imgy);
	game->imgs[4] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/arka.xpm", &game->imgx, &game->imgy);
	game->imgs[5] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/collectable.xpm", &game->imgx, &game->imgy);
	game->imgs[6] = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./assets/exit.xpm", &game->imgx, &game->imgy);
}

void	view(t_game *game, int x, int y, int i)
{
	while (game->bf[i])
	{
		if (game->bf[i] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs[0], x, y);
		if (game->bf[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->char_pos, x, y);
			game->idx = i;
		}
		if (game->bf[i] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs[5], x, y);
		if (game->bf[i] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs[6], x, y);
		if (game->bf[i] == '\n')
		{
			x = -32;
			y += 32;
		}
		x += 32;
		i++;
	}
}

void	replace_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	view(game, x, y, i);
}

void	check_map(t_game *game, char *s)
{
	int	fd;
	int	i;

	check_ber(s);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_error("Verdiğiniz yolda dosya bulunamadı..!");
	game->bf = malloc(99999);
	if (!game->bf)
		malloc_error(fd, "Malloc olusturulamadı.");
	i = read(fd, game->bf, 99998);
	game->bf[i] = 0;
	close(fd);
	game->map = ft_split(game->bf, '\n');
	if (!game->map)
		split_error(game);
	check_col_row(game);
	check_walls(game);
	check_chars(game);
	check_rectangle(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.total_moves = 0;
		game.mlx_ptr = mlx_init();
		check_map(&game, argv[1]);
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.x * 32, \
		game.y * 32, argv[0]);
		make_images(&game);
		game.char_pos = game.imgs[1];
		replace_map(&game);
		mlx_hook(game.win_ptr, 2, 0, char_moves, &game);
		mlx_hook(game.win_ptr, 17, 1L << 17, close_with, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_error("Argüman hatası girildi.");
	return (0);
}
