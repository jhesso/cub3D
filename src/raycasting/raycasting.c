/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/12 17:27:17 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_blocks(t_map_data *data, int x, int y, uint32_t color)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < SIZE_B - 1)
	{
		block_x = 0;
		while (block_x < SIZE_B - 1)
		{
			mlx_put_pixel(data->mlx_data->window, x + block_x, y + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

static void	draw_map(t_map_data *data)
{
	int x;
	int y;
	uint32_t color;

	y = 0;
	while (data->map[y] && (y * SIZE_B) < HEIGHT_W)
	{
		x = 0;
		while (data->map[y][x] && (x * SIZE_B) < WIDTH_W)
		{
			if (x < (int)ft_strlen(data->map[y]) && data->map[y][x] == '1')
				color = 0x808080;
			else if (x < (int)ft_strlen(data->map[y]) \
				&& (data->map[y][x] == '0' || (data->map[y][x] != ' ' \
				&& ft_strrchr("NSWE", data->map[y][x]))))
				color = 0x0000FF;
			else
				color = 0x000000;
			draw_blocks(data, x * SIZE_B, y * SIZE_B, color);
			x++;
		}
		y++;
	}
}

static void	draw_player_block(t_map_data *data, float x, float y, uint32_t color)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (data->starting_pos.x >= 0 && data->starting_pos.y >= 0 && block_y < SIZE_P)
	{
		block_x = 0;
		while (block_x < SIZE_P)
		{
			mlx_put_pixel(data->mlx_data->window, x + block_x, y + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

static void	draw_player(t_map_data *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while ((block_y * SIZE_B) < HEIGHT_W)
	{
		block_x = 0;
		while ((block_x * SIZE_B) < WIDTH_W)
		{
			draw_player_block(data, (data->starting_pos.x ), (data->starting_pos.y), 0xDFFF00);
			block_x++;
		}
		block_y++;
	}
}

void	draw_nose(t_map_data *data)
{
	t_float_v	angle;
	t_float_v	pos;
	float		i;

	angle.x = data->starting_angle.x;
	angle.y = data->starting_angle.y;
	pos.x = data->starting_pos.x + SIZE_P / 2;
	pos.y = data->starting_pos.y + SIZE_P / 2;
	i = 0;
	while (i < 20 && pos.y > -1 && pos.x > -1)
	{
		mlx_put_pixel(data->mlx_data->window, pos.x, pos.y, 0xF000FF);
		pos.y += angle.y;
		pos.x += angle.x;
		i++;
	}
}

// static void	draw_fov(t_map_data *data)
// {

// }

// static void	draw_floor_ceiling(t_map_data *data)
// {
// 	t_vector	window;

// 	window.y = 0;
// 	while (window.y < HEIGHT_W / 2)
// 	{
// 		window.x = 0;
// 		while (window.x < WIDTH_W)
// 		{
// 			mlx_put_pixel(data->mlx_data->window, window.x, window.y, data->mlx_data->ceiling);
// 			window.x++;
// 		}
// 		window.y++;
// 	}
// 	while (window.y < HEIGHT_W)
// 	{
// 		window.x = 0;
// 		while (window.x < WIDTH_W)
// 		{
// 			mlx_put_pixel(data->mlx_data->window, window.x, window.y, data->mlx_data->floor);
// 			window.x++;
// 		}
// 		window.y++;
// 	}

// }

void	raycasting(void *ptr)
{
	t_map_data *data;
	t_vector cord;

	data = (t_map_data *)ptr;
	cord.y = 0;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_data->mlx);
	// this while loop will draw the background!
	while (cord.y < HEIGHT_W)
	{
		cord.x = 0;
		while (cord.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, cord.x, cord.y, 0x000000);
			cord.x++;
		}
		cord.y++;
	}
	// draw_floor_ceiling(data);


	//this will be used for the minimap, with other commented out functions!
	draw_map(data);
	draw_player(data);
	draw_nose(data);
	// draw_fov(data);
}
