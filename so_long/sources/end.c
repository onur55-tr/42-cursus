/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:58:02 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 18:40:12 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_strcmp(const char *dest, const char *source)
{
	while (*dest == *source && *dest)
	{
		dest++;
		source++;
	}
	return (*dest - *source);
}

int	check_ber(char *path)
{
	char	*ext;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strncmp(".ber", ext, ft_strlen(".ber")) != 0)
		return (0);
	return (1);
}

int	close_with(void)
{
	exit(1);
	return (0);
}

void	finish_game(t_game *game)
{
	if (game->collectable == game->score)
		free_last(game);
}
