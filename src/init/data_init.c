/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:43:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/12 17:11:38 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_mlx_data	*init_mlx_data(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
	{
		ft_printf(2, "%s", X_MALLOC);
		return (NULL);
	}
	mlx_data->mlx = NULL;
	mlx_data->window = NULL;
	mlx_data->north = NULL;
	mlx_data->south = NULL;
	mlx_data->west = NULL;
	mlx_data->east = NULL;
	mlx_data->floor = -1;
	mlx_data->ceiling = -1;
	return (mlx_data);
}

static bool	init_map_data(t_map_data *data)
{
	data->file_splitted = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->floor = malloc(sizeof(int) * 3);
	data->ceiling = malloc(sizeof(int) * 3);
	if (!data->floor || !data->ceiling)
		return (false);
	data->floor[0] = -1;
	data->ceiling[0] = -1;
	data->pos.x = 0;
	data->pos.y = 0;
	data->dir.x = 0;
	data->dir.y = 0;
	data->angle = 0;
	data->map_w = 0;
	data->map_h = 0;
	data->map = NULL;
	data->mlx_data = init_mlx_data();
	if (!data->mlx_data)
		return (false);
	return (true);
}

bool	data_init(t_map_data *data, char *map)
{
	if (!init_map_data(data))
		return (false);
	if (!read_map(data, map))
		return (false);
	if (!parse_file(data))
		return (false);
	if (!validate_elements(data))
		return (false);
	if (!validate_map(data))
		return (false);
	if (!init_mlx(data))
		return (false);
	return (true);
}
