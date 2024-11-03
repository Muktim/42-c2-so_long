/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:48:35 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:52:56 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pass_map_to_gdata(t_map **map, t_game *gdata)
{
	int		i;
	t_map	*temp;

	temp = *map;
	i = 0;
	gdata->map = malloc(sizeof(char *) * (gdata->m_height + 1));
	while (i < gdata->m_height && temp != NULL)
	{
		gdata->map[i] = ft_strdup(temp->map_str);
		if (gdata->map[i] == NULL && i < gdata->m_height)
		{
			free_list(map);
			exit_clean("Error - Malloc - Oh my memories!!", 3, gdata);
		}
		i++;
		temp = temp->next;
	}
	gdata->map[i] = NULL;
}

static void	edit_node(t_map **node, char *temp)
{
	int		len;
	int		i;
	char	*upd_temp;

	len = 0;
	i = 0;
	while (temp[len] != '\n' && temp[len] != '\0')
		len++;
	upd_temp = malloc(sizeof(char) * (len + 1));
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		upd_temp[i] = temp[i];
		i++;
	}
	upd_temp[i] = '\0';
	(*node)->map_str = upd_temp;
	(*node)->next = NULL;
	free(temp);
}

static void	append_node(t_map **map, t_map *node, t_game *gdata)
{
	t_map	*temp;

	temp = *map;
	if (map == NULL)
		return ;
	if (*map != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	else
		*map = node;
	gdata->m_height++;
}

static void	read_into_linked_list(t_map **map, t_game *gdata)
{
	t_map	*node;
	int		eflag;
	char	*temp;

	eflag = 0;
	while (eflag == 0)
	{
		node = malloc(sizeof(t_map));
		if (node == NULL)
		{
			free_list(map);
			exit_clean("Error - Malloc - Oh my memories!!", 2, gdata);
		}
		temp = get_next_line(gdata->map_fd);
		if (temp != NULL)
		{
			edit_node(&node, temp);
			append_node(map, node, gdata);
		}
		else
		{
			eflag = 1;
			free(node);
		}
	}
}

void	create_map(t_game *gdata, char **av)
{
	t_map	*map;

	map = NULL;
	gdata->map_fd = open(av[1], O_RDONLY);
	if (gdata->map_fd == -1)
	{
		perror("Error - Open - The scholar got eaten by the dolphins!");
		exit (2);
	}
	read_into_linked_list(&map, gdata);
	pass_map_to_gdata(&map, gdata);
	free_list(&map);
}
