/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:12:46 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:56:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_tmlx(t_mlx *mlxstruct)
{
	if (mlxstruct == NULL)
		return ;
	if (mlxstruct->win_ptr != NULL)
		mlx_destroy_window(mlxstruct->mlx_ptr, mlxstruct->win_ptr);
	if (mlxstruct->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlxstruct->mlx_ptr);
		free(mlxstruct->mlx_ptr);
	}
	free(mlxstruct);
}

static void	clean_timg(t_game *gdata)
{
	t_img	*temp;

	temp = gdata->imgstruct;
	if (temp == NULL)
		return ;
	if (temp->wall != NULL)
		mlx_destroy_image(gdata->mlxstruct->mlx_ptr, temp->wall);
	if (temp->empty != NULL)
		mlx_destroy_image(gdata->mlxstruct->mlx_ptr, temp->empty);
	if (temp->player != NULL)
		mlx_destroy_image(gdata->mlxstruct->mlx_ptr, temp->player);
	if (temp->coll != NULL)
		mlx_destroy_image(gdata->mlxstruct->mlx_ptr, temp->coll);
	if (temp->exit != NULL)
		mlx_destroy_image(gdata->mlxstruct->mlx_ptr, temp->exit);
	free (gdata->imgstruct);
	gdata->imgstruct = NULL;
}

void	exit_clean(char	*msg, int flag, t_game *gdata)
{
	int	i;

	if (msg != NULL)
		ft_putstr_fd(msg, 1);
	i = 0;
	if (gdata->map && gdata->map[i])
	{
		while (i < gdata->m_height && gdata->map[i])
		{
			free (gdata->map[i]);
			gdata->map[i] = NULL;
			i++;
		}
	}
	if (gdata->map)
		free(gdata->map);
	gdata->map = NULL;
	clean_timg(gdata);
	clean_tmlx(gdata->mlxstruct);
	exit (flag);
}

void	free_list(t_map **map)
{
	t_map	*temp;

	while (map && *map)
	{
		if ((*map)->map_str != NULL)
		{
			free ((*map)->map_str);
			(*map)->map_str = NULL;
		}
		temp = (*map)->next;
		free (*map);
		*map = temp;
		temp = NULL;
	}
}
