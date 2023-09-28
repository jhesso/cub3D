/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/28 22:38:44 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_textures(t_map_data *data)
{
	data->mlx_data->north = mlx_load_png(data->north);
	if (!data->mlx_data->north)
		return (error_message(X_MLX));
	data->mlx_data->south = mlx_load_png(data->south);
	if (!data->mlx_data->south)
		return (error_message(X_MLX));
	data->mlx_data->west = mlx_load_png(data->west);
	if (!data->mlx_data->west)
		return (error_message(X_MLX));
	data->mlx_data->east = mlx_load_png(data->east);
	if (!data->mlx_data->east)
		return (error_message(X_MLX));
	return (true);
}

bool	init_mlx(t_map_data *d)
{
	if (!(d->mlx_data->mlx = mlx_init(1920, 1024, "cub3D", true)))
		return (error_message(X_MLX));
	if (!init_textures(d))
		return (false);
	if (!(d->mlx_data->window = mlx_new_image(d->mlx_data->mlx, 1920, 1024)))
	{
		mlx_close_window(d->mlx_data->mlx);
		return (error_message(X_MLX));
	}
	if (mlx_image_to_window(d->mlx_data->mlx, d->mlx_data->window, 0, 0) == -1)
	{
		mlx_close_window(d->mlx_data->mlx);
		return (error_message(X_MLX));
	}
	// mlx_loop_hook(d->mlx_data->mlx, ft_randomize, mlx);
	// mlx_loop_hook(d->mlx_data->mlx, ft_hook, mlx); //got this from the MLX42 test!
	mlx_loop(d->mlx_data->mlx);
	mlx_terminate(d->mlx_data->mlx);
	return (true);
}
