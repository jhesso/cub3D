/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:38:33 by dgerguri          #+#    #+#             */
/*   Updated: 2023/10/08 13:57:36 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_map_data *data)
{
	float	x;
	float	y;

	x = data->starting_angle.y * 0.5;
	y = -data->starting_angle.x * 0.5;
	data->starting_pos.x = data->starting_pos.x + x;
	data->starting_pos.y = data->starting_pos.y + y;
}

void	move_down(t_map_data *data)
{
	float	x;
	float	y;

	x = -data->starting_angle.y * 0.5;
	y = data->starting_angle.x * 0.5;;
	data->starting_pos.x = data->starting_pos.x + x;
	data->starting_pos.y = data->starting_pos.y + y;
}

void	move_left(t_map_data *data)
{
	float	x;
	float	y;

	x = data->starting_pos.x - data->starting_angle.x * 0.5;
	y = data->starting_pos.y - data->starting_angle.y * 0.5;;
	data->starting_pos.x = x;
	data->starting_pos.y = y;
}

void	move_right(t_map_data *data)
{
	float	x;
	float	y;

	x = data->starting_pos.x + data->starting_angle.x * 0.5;
	y = data->starting_pos.y + data->starting_angle.y * 0.5;;
	data->starting_pos.x = x;
	data->starting_pos.y = y;
}

void	move_left_arrow(t_map_data *data)
{
	float	x;
	float	y;

	x = data->starting_angle.y * 0.5;
	y = -data->starting_angle.x * 0.5;;
	data->starting_pos.x = data->starting_pos.x + x;
	data->starting_pos.y = data->starting_pos.y + y;
}

void	move_right_arrow(t_map_data *data)
{
	float	x;
	float	y;

	x = -data->starting_angle.y * 0.5;
	y = data->starting_angle.x * 0.5;;
	data->starting_pos.x = data->starting_pos.x + x;
	data->starting_pos.y = data->starting_pos.y + y;
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
