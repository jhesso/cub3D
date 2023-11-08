/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:00:19 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/08 16:17:17 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this is just for testing!
void	print_struct(t_map_data *data)
{
	int	i;

	i = 0;
	printf("------STRUCT-----\n");
	printf("NORTH: %s\n", data->north);
	printf("SOUTH: %s\n", data->south);
	printf("WEST: %s\n", data->west);
	printf("EAST: %s\n", data->east);
	printf("Floor: ");
	while (i < 3)
	{
		printf("  %d ", data->floor[i]);
		i++;
	}
	printf("\nCeiling: ");
	i = 0;
	while (i < 3)
	{
		printf("  %d ", data->ceiling[i]);
		i++;
	}
	printf("\n");
	printf("Pos: x: %f, y: %f\n", data->pos.x, data->pos.y);
	printf("view: x: %f, y: %f\n", data->dir.x, data->dir.y);
	printf("viewAngle: %f\n", data->angle);
	print_string_arr(data->map);
}

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
