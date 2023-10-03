/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/10/03 14:23:33 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_textures(t_map_data *data)
{ //check again the return value of mlx_texture_to_image, could possibly remove the protection
	mlx_texture_t	*texture;

	texture = mlx_load_png(data->north);
	data->mlx_data->north = mlx_texture_to_image(data->mlx_data->mlx, texture);
	if (!data->mlx_data->north)
		return (error_message(X_MLX));
	mlx_delete_texture(texture);
	texture = mlx_load_png(data->south);
	data->mlx_data->south = mlx_texture_to_image(data->mlx_data->mlx, texture);
	if (!data->mlx_data->south)
		return (error_message(X_MLX));
	mlx_delete_texture(texture);
	texture = mlx_load_png(data->west);
	data->mlx_data->west = mlx_texture_to_image(data->mlx_data->mlx, texture);
	if (!data->mlx_data->west)
		return (error_message(X_MLX));
	mlx_delete_texture(texture);
	texture = mlx_load_png(data->east);
	data->mlx_data->east = mlx_texture_to_image(data->mlx_data->mlx, texture);
	if (!data->mlx_data->east)
		return (error_message(X_MLX));
	mlx_delete_texture(texture);
	return (true);
}

bool	init_mlx(t_map_data *d)
{
	if (!(d->mlx_data->mlx = mlx_init(WIDTH_W, HEIGHT_W, "cub3D", true)))
		return (error_message(X_MLX));
	if (!init_textures(d))
		return (false);
	if (!(d->mlx_data->window = mlx_new_image(d->mlx_data->mlx, WIDTH_W, 1080)))
	{
		mlx_close_window(d->mlx_data->mlx);
		return (error_message(X_MLX));
	}
	if (mlx_image_to_window(d->mlx_data->mlx, d->mlx_data->window, 0, 0) == -1)
	{
		mlx_close_window(d->mlx_data->mlx);
		return (error_message(X_MLX));
	}
	mlx_loop_hook(d->mlx_data->mlx, &raycasting, d);
	// mlx_loop_hook(d->mlx_data->mlx, &moving, d); //got this from the MLX42 test!
	mlx_loop(d->mlx_data->mlx);
	return (true);
}
