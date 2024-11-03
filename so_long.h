/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:30:27 by mcoskune          #+#    #+#             */
/*   Updated: 2024/08/06 13:37:30 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./LIBFT/libft.h"
// # include "/home/mcoskune/so_long/minilibx-linux/mlx.h"

# define WALL "textures/wall.xpm"
# define EMPTY "textures/empty.xpm"
# define PLAYER "textures/player.xpm"
# define COLL "textures/collectable.xpm"
# define EXIT "textures/exit.xpm"

typedef struct s_map
{
	char			*map_str;
	struct s_map	*next;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*coll;
	void	*exit;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		map_fd;
	int		m_height;
	int		m_width;
	int		coll_count;
	int		p_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		num_of_move;
	t_mlx	*mlxstruct;
	t_img	*imgstruct;
}	t_game;

/*------- VALIDATE & INITIALIZE -------*/
void	input_validate(int ac, char **av);
void	clean_init(t_game *init);
void	clean_init_img(t_img **init);
void	create_map(t_game *gdata, char **av);
void	map_validate(t_game *gdata);

/*------- CLEANUP -------*/
void	free_list(t_map **map);
void	exit_clean(char	*msg, int flag, t_game *gdata);

/*------- MLX & WINDOW MANAGEMENT -------*/
void	mlx_handler(t_game *gdata);

/*------- GAME & INPUT -------*/
int		handle_key_input(int keysys, t_game *gdata);
int		close_window(t_game *gdata);
void	render_map(t_game *gdata);

#endif