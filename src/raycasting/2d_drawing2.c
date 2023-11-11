/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_drawing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:02:47 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 03:04:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_map_data *data)
{
	t_vector	window;

	window.y = 0;
	while (window.y < HEIGHT_W / 2)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y,
				data->mlx_data->ceiling);
			window.x++;
		}
		window.y++;
	}
	while (window.y < HEIGHT_W)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y,
				data->mlx_data->floor);
			window.x++;
		}
		window.y++;
	}
}

void	draw_minimap(t_map_data *data)
{
	draw_map(data);
	draw_player(data);
	draw_nose(data);
}
