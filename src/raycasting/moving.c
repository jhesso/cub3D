/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:38:33 by dgerguri          #+#    #+#             */
/*   Updated: 2023/10/07 12:52:18 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving(void *ptr)
{
	t_map_data *data;
	t_float_v	move;
	float		angle;

	data = (t_map_data *)ptr;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_W))
		move.x++;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_S))
		move.x--;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_A))
		move.y--;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_D))
		move.y++;
	angle = atanf(move.y / move.x) + data->s_angle;
	if (move.x < 0)
		angle = angle + M_PI;
	data->starting_pos.x = data->starting_pos.x + 0.5 * cosf(angle);
	data->starting_pos.y = data->starting_pos.y + 0.5 * sinf(angle);
}
