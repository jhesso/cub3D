/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/09 12:06:12 by dgerguri         ###   ########.fr       */
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
	uint32_t color;
	int	block_y;
	int	block_x;

	color = 0xDFFF00;
	block_y = 0;
	while ((block_y * SIZE_B) < HEIGHT_W)
	{
		block_x = 0;
		while ((block_x * SIZE_B) < WIDTH_W)
		{
			draw_player_block(data, (data->starting_pos.x ), (data->starting_pos.y), color);
			block_x++;
		}
		block_y++;
	}
}

void	raycasting(void *ptr)
{
	t_map_data *data;
	// uint32_t color;
	t_vector cord;

	data = (t_map_data *)ptr;
	// color = 0x000000;
	cord.y = 0;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_data->mlx);
	// while (cord.y < 1080)
	// {
	// 	cord.x = 0;
	// 	while (cord.x < WIDTH_W)
	// 	{
	// 		mlx_put_pixel(data->mlx_data->window, cord.x, cord.y, color);
	// 		cord.x++;
	// 	}
	// 	cord.y++;
	// }
	draw_map(data);
	draw_player(data);
}
