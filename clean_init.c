/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:04 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:52:45 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_init_img(t_img **init)
{
	(*init)->wall = NULL;
	(*init)->empty = NULL;
	(*init)->player = NULL;
	(*init)->coll = NULL;
	(*init)->exit = NULL;
	(*init)->pixel_ptr = NULL;
	(*init)->bpp = -1;
	(*init)->endian = -1;
	(*init)->line_len = -1;
}

void	clean_init(t_game *init)
{
	init->map = NULL;
	init->map_fd = -1;
	init->m_height = 0;
	init->m_width = 0;
	init->coll_count = 0;
	init->p_count = 0;
	init->e_count = 0;
	init->player_x = -1;
	init->player_y = -1;
	init->num_of_move = 0;
	init->mlxstruct = NULL;
	init->imgstruct = NULL;
}
