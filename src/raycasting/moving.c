/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:38:33 by dgerguri          #+#    #+#             */
/*   Updated: 2023/10/05 17:12:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *game, float x, float y)
{

}

void	move_down(t_game *game, float x, float y)
{

}

void	move_left(t_game *game, float x, float y)
{

}

void	move_right(t_game *game, float x, float y)
{

}

void	moving(void *ptr)
{
	t_map_data *data;

	data = (t_map_data *)ptr;
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_N))
		move_up(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_W))
	if (mlx_is_key_down(data->mlx_data->mlx, MLX_KEY_E))

}
