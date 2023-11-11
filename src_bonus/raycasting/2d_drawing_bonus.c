/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_drawing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:40:17 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_player_block(t_map_data *data, float x, float y, uint32_t color)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	printf("x: %f\n", x);

	while (x > SIZE_B * 5 && x < ((data->map_w - 6) * SIZE_B + ((SIZE_B - SIZE_P) / 2)))
		x = x - SIZE_B;
	while (y > SIZE_B * 3 && y < ((data->map_h - 4) * SIZE_B + ((SIZE_B - SIZE_P) / 2)))
		y = y - SIZE_B;
	if (x > ((data->map_w - 6) * SIZE_B + ((SIZE_B - SIZE_P) / 2)))
	{
		while (x > 320)
			x = x - 210;
	}
	if (y > ((data->map_h - 4) * SIZE_B + ((SIZE_B - SIZE_P) / 2)))
	{
		while (y > 160)
			y = y - 126;
	}
	while (x >= 0 && y >= 0 && block_y < SIZE_P)
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

void	draw_player(t_map_data *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while ((block_y * SIZE_B) < 10)
	{
		block_x = 0;
		while ((block_x * SIZE_B) < 20)
		{
			draw_player_block(data, data->pos.x, data->pos.y, 0xDFFF00);
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

	angle.x = data->dir.x;
	angle.y = data->dir.y;
	pos.x = data->pos.x + SIZE_P / 2;
	pos.y = data->pos.y + SIZE_P / 2;
	// printf("X : %f\n", pos.x);make
	while (pos.x > (SIZE_B * 5) + 2)
		pos.x = pos.x - SIZE_B;
	while (pos.y > (SIZE_B * 3) + 2)
		pos.y = pos.y - SIZE_B;
	i = 0;
	while (i < 10 && pos.y > -1 && pos.x > -1)
	{
		mlx_put_pixel(data->mlx_data->window, pos.x, pos.y, 0xF000FF);
		pos.y += angle.y;
		pos.x += angle.x;
		i++;
	}
}

static void	draw_blocks(t_map_data *data, float x, float y, uint32_t color)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < SIZE_B - 1 && color)
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

static void	get_top_left_y_and_x(t_map_data *data, int *y, int *x, int type)
{
	int	pos_x;
	int	pos_y;

	pos_x = ((int)data->pos.x / SIZE_B) + 1;
	pos_y = ((int)data->pos.y / SIZE_B) + 1;
	if (type == 1)
	{
		if (data->map_h > 6 && pos_y > data->map_h - 6 / 2)
			*y = data->map_h - 6;
		else if (pos_y > 6 / 2)
			*y = pos_y - 6 / 2;
		else
			*y = 0;
	}
	else if (type == 2)
	{
		if (data->map_w > 10 && pos_x > data->map_w - 10 / 2)
			*x = data->map_w - 10;
		else if (pos_x > 10 / 2)
			*x = pos_x - 10 / 2;
		else
			*x = 0;
	}
}

void draw_map_long(t_map_data *data, int row, int column, int x)
{
	int y;
	uint32_t color;

	get_top_left_y_and_x(data, &y, 0, 1);
	while (data->map[y] && row < 6)
	{
		column = 0;
		get_top_left_y_and_x(data, 0, &x, 2);
		while (column < 10)
		{
			if (x < (int)ft_strlen(data->map[y]) && data->map[y][x] == '1')
				color = 0x808080;
			else if (x < (int)ft_strlen(data->map[y]) \
				&& (data->map[y][x] == '0' || (data->map[y][x] != ' ' \
				&& ft_strrchr("NSWE", data->map[y][x]))))
				color = 0x0000FF;
			else
				break ;
			draw_blocks(data, column * SIZE_B, row * SIZE_B, color);
			x++;
			column++;
		}
		y++;
		row++;
	}
}


void	draw_map(t_map_data *data)
{
	int x;
	int y;
	uint32_t color;

	x = 0;
	y = 0;
	if (data->map_w > 10 || data->map_h > 6)
		draw_map_long(data, 0, 0, 0);
	else
	{
		while (data->map[y] && y < 6)
		{
			x = 0;
			while (data->map[y][x] && x < 10)
			{
				if (x < (int)ft_strlen(data->map[y]) && data->map[y][x] == '1')
					color = 0x808080;
				else if (x < (int)ft_strlen(data->map[y]) \
					&& (data->map[y][x] == '0' || (data->map[y][x] != ' ' \
					&& ft_strrchr("NSWE", data->map[y][x]))))
					color = 0x0000FF;
				else
					break;
				draw_blocks(data, x * SIZE_B, y * SIZE_B, color);
				x++;
			}
			y++;
		}
	}
}

void	draw_minimap(t_map_data *data)
{
	draw_map(data);
	draw_player(data);
	draw_nose(data);
}
