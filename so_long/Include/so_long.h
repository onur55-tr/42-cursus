/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:31:29 by odursun           #+#    #+#             */
/*   Updated: 2022/03/14 21:11:35 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Minilibx/mlx.h"
# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"

typedef struct s_game {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*char_pos;
	void	**imgs;
	char	**map;
	char	*bf;	
	int		x;
	int		y;
	int		imgx;
	int		imgy;
	int		idx;
	int		score;
	int		collectable;
	int		total_moves;
}				t_game;

typedef enum e_key
{
	A = 0,
	W = 13,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53,
	Q = 0,
	R = 15
}	t_key;

char	**ft_split(char const *s, char c);
int		ft_printf(const char *str, ...);
void	*free_last(t_game *game);
int		ft_error(char *message);
void	free_map(t_game *game);
void	malloc_error(int fd, char *message);
void	split_error(t_game *game);
void	check_col_row(t_game *game);
void	check_walls(t_game *game);
void	check_chars(t_game *game);
void	check_rectangle(t_game *game);
int		check_ber(char *s);
void	map_err(t_game *game, char sgn_err);
void	finish_game(t_game *game);
int		close_with(void);
void	replace_map(t_game *game);
int		char_moves(int keycode, t_game *gm);

#endif
