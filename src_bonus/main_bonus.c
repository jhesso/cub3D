/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:00:19 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/12 14:47:08 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_map_data	data;

	if (argc == 2)
	{
		if (data_init(&data, argv[1]))
			ft_printf(1, "Everything working fine!\n");
		else
		{
			cleanup(&data);
			return (1);
		}
	}
	else
	{
		ft_printf(2, "%s", X_VALID_ARGUMENTS);
		return (1);
	}
	cleanup(&data);
	return (0);
}
