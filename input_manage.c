/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:26:59 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:55:18 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_p(int y_move, int x_move, t_game *gdata)
{
	if (gdata->map[gdata->player_y + y_move][gdata->player_x + x_move] == '1')
	{
		ft_printf("You can't walk into walls you dummy\n");
		return ;
	}
	if (gdata->map[gdata->player_y][gdata->player_x] != 'E')
		gdata->map[gdata->player_y][gdata->player_x] = '0';
	if (gdata->map[gdata->player_y + y_move][gdata->player_x + x_move] == 'E')
	{
		if (gdata->coll_count == 0)
			exit_clean("CONGRATS", 0, gdata);
		ft_printf("You can't go home yet, your mum is still mad at you\n");
	}
	if (gdata->map[gdata->player_y + y_move][gdata->player_x + x_move] == 'C')
		gdata->coll_count--;
	if (gdata->map[gdata->player_y + y_move][gdata->player_x + x_move] != 'E')
		gdata->map[gdata->player_y + y_move][gdata->player_x + x_move] = 'P';
	gdata->player_x += x_move;
	gdata->player_y += y_move;
	gdata->num_of_move++;
	ft_printf("Total Number of Moves: %d\n", gdata->num_of_move);
	render_map(gdata);
}

int	close_window(t_game *gdata)
{
	exit_clean("Exit - X button\n", 0, gdata);
	return (0);
}

int	handle_key_input(int keysys, t_game *gdata)
{
	if (keysys == XK_w)
		move_p(-1, 0, gdata);
	else if (keysys == XK_a)
		move_p(0, -1, gdata);
	else if (keysys == XK_s)
		move_p(1, 0, gdata);
	else if (keysys == XK_d)
		move_p(0, 1, gdata);
	else if (keysys == XK_Escape)
		exit_clean("Exit - ESC\n", 0, gdata);
	return (0);
}
