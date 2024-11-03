/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:24:22 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:55:49 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_images(t_game *gdata)
{
	t_img	*imgptr;
	int		x;
	int		y;

	imgptr = malloc(sizeof(t_img));
	if (imgptr == NULL)
		exit_clean("Error - Malloc - Oh malloc my love", 8, gdata);
	gdata->imgstruct = imgptr;
	clean_init_img(&imgptr);
	imgptr->wall = mlx_xpm_file_to_image(gdata->mlxstruct->mlx_ptr, \
		WALL, &y, &x);
	imgptr->empty = mlx_xpm_file_to_image(gdata->mlxstruct->mlx_ptr, \
		EMPTY, &y, &x);
	imgptr->player = mlx_xpm_file_to_image(gdata->mlxstruct->mlx_ptr, \
		PLAYER, &y, &x);
	imgptr->coll = mlx_xpm_file_to_image(gdata->mlxstruct->mlx_ptr, \
		COLL, &y, &x);
	imgptr->exit = mlx_xpm_file_to_image(gdata->mlxstruct->mlx_ptr, \
		EXIT, &y, &x);
	if (!imgptr->wall || !imgptr->empty || !imgptr->player || !imgptr->coll || \
		!imgptr->exit)
		exit_clean("Error - IMAGE - Quick, make a banana art", 9, gdata);
}

void	mlx_handler(t_game *gdata)
{
	t_mlx	*mlx_box;

	mlx_box = malloc (sizeof(t_mlx));
	if (mlx_box == NULL)
		exit_clean("Error - Malloc - WHHY MALLOC JUST WWWHY?!?", 6, gdata);
	gdata->mlxstruct = mlx_box;
	gdata->mlxstruct->mlx_ptr = mlx_init();
	if (gdata->mlxstruct->mlx_ptr == NULL)
		exit_clean("Error - MLXPTR - Chemical X for powerpuff girls", 7, gdata);
	gdata->mlxstruct->win_ptr = mlx_new_window(gdata->mlxstruct->mlx_ptr, \
		32 * gdata->m_width, 32 * gdata->m_height, "Best Worst Game");
	if (gdata->mlxstruct->win_ptr == NULL)
		exit_clean("Error - WINPTR - Windows sucks anyway", 8, gdata);
	initialize_images(gdata);
	render_map(gdata);
}
