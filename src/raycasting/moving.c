/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:38:33 by dgerguri          #+#    #+#             */
/*   Updated: 2023/10/20 15:33:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left(t_map_data *data)
{
	float	x;
	float	y;

	x = data->cord_dir.y * 0.5;
	y = -data->cord_dir.x * 0.5;
	data->pos.x = data->pos.x + x;
	data->pos.y = data->pos.y + y;
}

static void	move_right(t_map_data *data)
{
	float	x;
	float	y;

	x = -data->cord_dir.y * 0.5;
	y = data->cord_dir.x * 0.5;
	data->pos.x = data->pos.x + x;
	data->pos.y = data->pos.y + y;
}

static void	move_down(t_map_data *data)
{
	float	x;
	float	y;

	x = data->pos.x - data->cord_dir.x * 0.5;
	y = data->pos.y - data->cord_dir.y * 0.5;
	data->pos.x = x;
	data->pos.y = y;
}

static void	move_up(t_map_data *data)
{
	float	x;
	float	y;

	x = data->pos.x + data->cord_dir.x * 0.5;
	y = data->pos.y + data->cord_dir.y * 0.5;
	data->pos.x = x;
	data->pos.y = y;
}

static void	move_left_arrow(t_map_data *data)
{
	float	angle_x;

	angle_x = data->cord_dir.x;
	data->cord_dir.x = data->cord_dir.x * cos(-0.05) - data->cord_dir.y * sin(-0.05);
	data->cord_dir.y = angle_x * sin(-0.05) + data->cord_dir.y * cos(-0.05);
}

static void	move_right_arrow(t_map_data *data)
{
	float	angle_x;

	angle_x = data->cord_dir.x;
	data->cord_dir.x = data->cord_dir.x * cos(0.05) - data->cord_dir.y * sin(0.05);
	data->cord_dir.y = angle_x * sin(0.05) + data->cord_dir.y * cos(0.05);
}

void	moving(void *ptr)
{
	t_map_data *data;
	t_float_v	move;

	data = (t_map_data *)ptr;
	move.x = 0;
	move.y = 0;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_LEFT))
		move_left_arrow(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_RIGHT))
		move_right_arrow(data);
}
