/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/02 22:52:29 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_blocks(t_map_data *data, double x, double y, \
				unsigned int color)
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

static void	draw_2D_map(t_map_data *data)
{
	int x;
	int y;
	uint32_t color;

	y = 0;
	x = 0;
	while (data->map[y][x])
	{
		printf("x = %d  y= %d\n", x, y);
		x = 0;
		while (data->map[y][x])
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
	// (void)ptr;
	t_map_data *data = (t_map_data *)ptr;
	// printf("starting: %d    %d\n", 1920 - (data->starting_pos.x * 64), 1024 - (data->starting_pos.y * 64));

	t_vector cord;
	uint32_t color = 0x000000;

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
	draw_2D_map(data);
}
