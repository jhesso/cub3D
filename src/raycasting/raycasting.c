/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/20 14:35:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	draw_fov(t_map_data *data)
// {


// }

static void	draw_floor_ceiling(t_map_data *data)
{
	t_vector	window;

	window.y = 0;
	while (window.y < HEIGHT_W / 2)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y, data->mlx_data->ceiling);
			window.x++;
		}
		window.y++;
	}
	while (window.y < HEIGHT_W)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y, data->mlx_data->floor);
			window.x++;
		}
		window.y++;
	}

}

void	raycasting(void *ptr)
{
	t_map_data *data;
	t_vector 	cord;
	int			i;

	data = (t_map_data *)ptr;
	cord.y = 0;
	i = 0;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_data->mlx);
	// this while loop will draw the background, maybe should be deleted in the end!
	// while (cord.y < HEIGHT_W)
	// {
	// 	cord.x = 0;
	// 	while (cord.x < WIDTH_W)
	// 	{
	// 		mlx_put_pixel(data->mlx_data->window, cord.x, cord.y, 0x000000);
	// 		cord.x++;
	// 	}
	// 	cord.y++;
	// }
	draw_floor_ceiling(data);
	//this will be used for the minimap, with other commented out functions!
	draw_map(data);
	draw_player(data);
	draw_nose(data);
	print_struct(data);
	while (i < WIDTH_W)
	{

		// draw_fov(data);
		// draw_3d(data);
		i++;
	}
}
