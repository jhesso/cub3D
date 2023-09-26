/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:00:19 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/26 18:19:02 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_struct(t_map_data *data) // this is just for testing!
{
	printf("------STRUCT-----\n");
	printf("NORTH: %s\n", data->north);
	printf("SOUTH: %s\n", data->south);
	printf("WEST: %s\n", data->west);
	printf("EAST: %s\n", data->east);
	int  i  = 0;
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
	print_string_arr(data->map);
}

int	main(int argc, char **argv)
{
	t_map_data	data;

	if (argc == 2)
	{
		if (map_data(&data, argv[1]))
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
