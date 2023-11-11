/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:38:33 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/11 18:27:54 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	move_left(t_map_data *data)
{
	float	x;
	float	y;

	x = data->dir.y * SPEED;
	y = -data->dir.x * SPEED;
	if (check_validity(data, data->pos.x + x, data->pos.y + y))
	{
		data->pos.x = data->pos.x + x;
		data->pos.y = data->pos.y + y;
	}
}

static void	move_right(t_map_data *data)
{
	float	x;
	float	y;

	x = -data->dir.y * SPEED;
	y = data->dir.x * SPEED;
	if (check_validity(data, data->pos.x + x, data->pos.y + y))
	{
		data->pos.x = data->pos.x + x;
		data->pos.y = data->pos.y + y;
	}
}

static void	move_down(t_map_data *data)
{
	float	x;
	float	y;

	x = data->pos.x - data->dir.x * SPEED;
	y = data->pos.y - data->dir.y * SPEED;
	if (check_validity(data, x, y))
	{
		data->pos.x = x;
		data->pos.y = y;
	}
}

static void	move_up(t_map_data *data)
{
	float	x;
	float	y;

	x = data->pos.x + data->dir.x * SPEED;
	y = data->pos.y + data->dir.y * SPEED;
	if (check_validity(data, x, y))
	{
		data->pos.x = x;
		data->pos.y = y;
	}
}

void	moving(void *ptr)
{
	t_map_data	*data;

	data = (t_map_data *)ptr;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_LEFT))
		turn_player(data, MLX_KEY_LEFT);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_RIGHT))
		turn_player(data, MLX_KEY_RIGHT);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_I))
		lookat(data, NORTH);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_J))
		lookat(data, WEST);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_K))
		lookat(data, SOUTH);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_L))
		lookat(data, EAST);
}
