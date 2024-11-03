/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:16:51 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 16:01:26 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	output_text(int x, int y, void *img, t_game *gdata)
{
	char	text[30];
	char	*temp;

	temp = ft_itoa(gdata->num_of_move);
	if (temp == NULL)
		return ;
	ft_strlcpy(text, "Current Number of Moves: ", 30);
	ft_strlcat(text, temp, 30);
	mlx_string_put(gdata->mlxstruct->mlx_ptr, gdata->mlxstruct->win_ptr, 16, \
	16, 0xFFFFFF, text);
	free (temp);
	if (img != NULL)
		mlx_put_image_to_window(gdata->mlxstruct->mlx_ptr, \
				gdata->mlxstruct->win_ptr, img, 32 * x, 32 * y);
}

void	render_map(t_game *gdata)
{
	int		x;
	int		y;
	void	*img;

	y = -1;
	while (++y < gdata->m_height)
	{
		x = -1;
		while (++x < gdata->m_width)
		{
			img = NULL;
			if (gdata->map[y][x] == '1')
				img = gdata->imgstruct->wall;
			else if (gdata->map[y][x] == '0')
				img = gdata->imgstruct->empty;
			else if (gdata->map[y][x] == 'P')
				img = gdata->imgstruct->player;
			else if (gdata->map[y][x] == 'C')
				img = gdata->imgstruct->coll;
			else if (gdata->map[y][x] == 'E')
				img = gdata->imgstruct->exit;
			output_text(x, y, img, gdata);
		}
	}
}
