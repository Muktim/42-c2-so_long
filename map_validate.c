/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:39:09 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/24 10:48:38 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	reverse_the_damage(t_game *gdata)
{
	int		x;
	int		y;

	x = 0;
	while (x < gdata->m_width)
	{
		y = 0;
		while (y < gdata->m_height)
		{
			if (gdata->map[y][x] == '2')
				gdata->map[y][x] = '0';
			else if (gdata->map[y][x] == 'c')
				gdata->map[y][x] = 'C';
			else if (gdata->map[y][x] == 'e')
				gdata->map[y][x] = 'E';
			else if (gdata->map[y][x] == 'p')
				gdata->map[y][x] = 'P';
			y++;
		}
		x++;
	}
}

static void	check_valid_path(t_game *gdata)
{
	int		i;
	int		k;
	char	c;

	i = 0;
	while (i < gdata->m_width)
	{
		k = 0;
		while (k < gdata->m_height)
		{
			c = gdata->map[k][i];
			if (c == 'E' || c == 'C')
				exit_clean("Error - No Path - I nommed all bread\n", 5, gdata);
			k++;
		}
		i++;
	}
	reverse_the_damage(gdata);
}

static void	flood_paint_path(t_game *gdata, int x, int y)
{
	if (x < 0 || y < 0 || x >= gdata->m_width || y >= gdata->m_height)
		return ;
	if (gdata->map[y][x] == '1')
		return ;
	if (gdata->map[y][x] == '2' || gdata->map[y][x] == 'c' || \
		gdata->map[y][x] == 'e' || gdata->map[y][x] == 'p')
		return ;
	if (gdata->map[y][x] == '0')
		gdata->map[y][x] = '2';
	if (gdata->map[y][x] == 'C')
		gdata->map[y][x] = 'c';
	if (gdata->map[y][x] == 'E')
		gdata->map[y][x] = 'e';
	if (gdata->map[y][x] == 'P')
		gdata->map[y][x] = 'p';
	flood_paint_path(gdata, x + 1, y);
	flood_paint_path(gdata, x - 1, y);
	flood_paint_path(gdata, x, y + 1);
	flood_paint_path(gdata, x, y - 1);
}

static void	line_validate(int i, t_game *gdata)
{
	int		k;
	char	c;

	k = 0;
	while (k < (int)ft_strlen(gdata->map[i]))
	{
		c = gdata->map[i][k];
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			exit_clean("Error - Map Tile - Sus character detected\n", 4, gdata);
		if ((i == 0 || i == gdata->m_height - 1) && c != '1')
			exit_clean("Error - Map - Does your house has walls?\n", 4, gdata);
		else if ((k == 0 || k == gdata->m_width - 1) && c != '1')
			exit_clean("Error - Map - Does your house has walls?\n", 4, gdata);
		if (gdata->map[i][k] == 'P')
		{
			gdata->p_count++;
			gdata->player_x = k;
			gdata->player_y = i;
		}
		else if (gdata->map[i][k] == 'C')
			gdata->coll_count++;
		else if (gdata->map[i][k] == 'E')
			gdata->e_count++;
		k++;
	}
}

void	map_validate(t_game *gdata)
{
	int	i;

	i = 0;
	gdata->m_width = ft_strlen(gdata->map[0]);
	if (gdata->m_width <= 0)
	{
		ft_printf("Error - Map size - String theory is not solved yet\n");
		exit_clean(NULL, 4, gdata);
	}
	while (i < gdata->m_height)
	{
		line_validate(i, gdata);
		if ((int)ft_strlen(gdata->map[i]) != gdata->m_width)
			exit_clean("Error - Map - It's called G E O M E T R Y\n", 4, gdata);
		i++;
	}
	if (gdata->coll_count < 1 || gdata->p_count != 1 || gdata->e_count != 1)
		exit_clean("Error - Map Content - Forgot something?\n", 4, gdata);
	flood_paint_path(gdata, gdata->player_x, gdata->player_y);
	check_valid_path(gdata);
}
