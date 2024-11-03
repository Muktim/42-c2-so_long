/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:30:05 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:52:24 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	gdata;

	input_validate(ac, av);
	clean_init(&gdata);
	create_map(&gdata, av);
	map_validate(&gdata);
	mlx_handler(&gdata);
	mlx_key_hook(gdata.mlxstruct->win_ptr, handle_key_input, &gdata);
	mlx_hook(gdata.mlxstruct->win_ptr, 17, 0, close_window, &gdata);
	mlx_loop(gdata.mlxstruct->mlx_ptr);
	exit_clean(NULL, 0, &gdata);
}
