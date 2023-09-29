/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:51 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/29 21:48:25 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup_mlx_data(t_mlx_data *data)
{
	if (data->mlx)
		mlx_terminate(data->mlx);
	if (data->window)
		mlx_delete_image(data->mlx, data->window);
	if (data->north)
		mlx_delete_image(data->mlx, data->north);
	if (data->south)
		mlx_delete_image(data->mlx, data->south);
	if (data->west)
		mlx_delete_image(data->mlx, data->west);
	if (data->east)
		mlx_delete_image(data->mlx, data->east);
}

void	cleanup(t_map_data *data)
{
	if (data->file_splitted)
		free_array(data->file_splitted);
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		free_array(data->map);
	if (data->mlx_data)
	{
		cleanup_mlx_data(data->mlx_data);
		free(data->mlx_data);
	}
}
