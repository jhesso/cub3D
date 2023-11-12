/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/12 13:36:51 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	init_textures(t_map_data *data)
{
	data->mlx_data->north = mlx_load_png(data->north);
	if (!data->mlx_data->north)
		return (error_message(X_MLX));
	data->mlx_data->east = mlx_load_png(data->east);
	if (!data->mlx_data->east)
		return (error_message(X_MLX));
	data->mlx_data->south = mlx_load_png(data->south);
	if (!data->mlx_data->south)
		return (error_message(X_MLX));
	data->mlx_data->west = mlx_load_png(data->west);
	if (!data->mlx_data->west)
		return (error_message(X_MLX));
	return (true);
}

static void	get_map_size(t_map_data *data)
{
	int	i;
	int	w;

	i = 0;
	while (data->map[i])
	{
		w = ft_strlen(data->map[i]);
		if (w > data->map_w)
			data->map_w = w;
		i++;
	}
	data->map_h = i;
}

bool	init_mlx(t_map_data *d)
{
	d->map_c = duplicate_map(d->map);
	get_map_size(d);
	if (!pad_map(d))
		return (false);
	d->mlx_data->mlx = mlx_init(WIDTH_W, HEIGHT_W, "cub3D", true);
	if (!d->mlx_data->mlx)
		return (error_message(X_MLX));
	if (!init_textures(d))
		return (false);
	d->mlx_data->window = mlx_new_image(d->mlx_data->mlx, WIDTH_W, 1080);
	if (!d->mlx_data->window)
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
	mlx_loop_hook(d->mlx_data->mlx, &moving, d);
	mlx_loop(d->mlx_data->mlx);
	return (true);
}
