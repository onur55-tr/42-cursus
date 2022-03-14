/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:01:24 by iyarikan          #+#    #+#             */
/*   Updated: 2022/03/14 19:35:26 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

/*
* checkwalls
* i == 0 durumu:
* i = 0 veya satırdan 1 eksiğine eşitse karakter hatası verdir.
* j == 0 durumu:
* j 0 veya sütundan 1 eksiğine eşitse duvar hatası verdir.
* -------------------------------------------------------------------------
* checkcolrow
* satır (y) ve sütunları kontrol edilir. i = 1 durumunda yani
* 2. satırdan başlatıyoruz. İlk satırı sayıp game->x e aktarıyoruz.
* game->map i'sinden lenghti game->x'e ilk satıra eşit mi diye 
* kontrol ediyoruz.
* whileden önce ***game->y = 0; game->x = 0;***
* -------------------------------------------------------------------------
* checkchars
* karakterin 01PCEF olması gerekiyor. Bunun dışında başka karakter varsa
* hata verdir.
* PE'den sadece bir tane olması gerekiyor ve collectende en az 1 tane
* olması şart.
* whileden önce ***;***
* ------------------------------------------------------------------------
* check_rectangle
* bf'un indexinden başlayarak satır sayısını hesapladık.
* count'um game->y(satır) eşit değillerse dikdörtgen değildir.
*/

void	check_col_row(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->y = 0;
	while (game->map[i++])
		game->y++;
	i = 0;
	game->x = 0;
	while (game->map[0][i++])
		game->x++;
	i = 1;
	while (i < game->y)
	{
		j = ft_strlen(game->map[i++]);
		if (j != game->x)
			map_err(game, '0');
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->y - 1)
			{
				if (game->map[i][j] != '1')
					map_err(game, '2');
			}
			else if (j == 0 || j == game->x - 1)
				if (game->map[i][j] != '1')
					map_err(game, '1');
			j++;
		}
		i++;
	}
}

void	check_chars(t_game *game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	game->collectable = 0;
	while (game->bf[i])
	{
		if (game->bf[i] == 'P')
			p++;
		else if (game->bf[i] == 'C')
			game->collectable++;
		else if (game->bf[i] == 'E')
			e++;
		else if (game->bf[i] != '0' && game->bf[i] != '1' \
		&& game->bf[i] != '\n')
			map_err(game, '2');
		i++;
	}
	if (p != 1 || e != 1 || game->collectable < 1)
		map_err(game, '2');
}

void	check_rectangle(t_game *game)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (game->bf[i])
	{
		if (game->bf[i] == '\n')
			count++;
		i++;
	}
	if (count != game->y)
		map_err(game, '3');
}
