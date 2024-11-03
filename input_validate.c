/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:31:22 by mcoskune          #+#    #+#             */
/*   Updated: 2024/07/30 12:52:33 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	i -= 4;
	if (ft_strncmp(&av[1][i], ".ber", 4) != 0)
	{
		ft_printf("Error\nMap Extension - Dangerous fish detected!!\n");
		exit(1);
	}
}

void	input_validate(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
			ft_printf("Error\nAC - Fish are starving\n");
		else
			ft_printf("Error\nAC - Fish are getting obese\n");
		exit (1);
	}
	check_extension(av);
}
