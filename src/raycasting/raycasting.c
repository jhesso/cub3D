/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/03 13:09:32 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_blocks(t_map_data *data, int x, int y, unsigned int color)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < 64 - 1)
	{
		block_x = 0;
		while (block_x < 64 - 1)
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
	while (data->map[y] && (y * 64) < 1024)
	{
		x = 0;
		while (data->map[y][x] && (x * 64) < 1920)
		{
			if (x < (int)ft_strlen(data->map[y]) && data->map[y][x] == '1')
				color = 0x808080;
			else if (x < (int)ft_strlen(data->map[y]) && data->map[y][x] == '0')
				color = 0xC0C0C0;
			else
				color = 0x0000FF;
			draw_blocks(data, x * 64, y * 64, color);
			x++;
		}
		y++;
	}
}

void	raycasting(void *ptr)
{
	t_map_data *data;
	uint32_t color;
	t_vector cord;

	data = (t_map_data *)ptr;
	color = 0x000000;
	cord.y = 0;
	while (cord.y < 1080)
	{
		cord.x = 0;
		while (cord.x < 1920)
		{
			mlx_put_pixel(data->mlx_data->window, cord.x, cord.y, color);
			cord.x++;
		}
		cord.y++;
	}
	draw_map(data);
}
