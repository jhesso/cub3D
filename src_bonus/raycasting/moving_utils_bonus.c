/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:52:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 18:29:39 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	turn_player(t_map_data *data, int keycode)
{
	if (keycode == MLX_KEY_LEFT)
		data->angle = fix_angle(data->angle + 5);
	else
		data->angle = fix_angle(data->angle - 5);
	data->dir.x = cos(deg_to_rad(data->angle));
	data->dir.y = -sin(deg_to_rad(data->angle));
}

void	lookat(t_map_data *data, int dir)
{
	if (dir == NORTH)
		data->angle = 90;
	if (dir == EAST)
		data->angle = 0;
	if (dir == SOUTH)
		data->angle = 270;
	if (dir == WEST)
		data->angle = 180;
	data->dir.x = cos(deg_to_rad(data->angle));
	data->dir.y = -sin(deg_to_rad(data->angle));
}

bool	check_validity(t_map_data *data, float x, float y)
{
	int	x_pos;
	int	y_pos;

	x_pos = x / SIZE_B;
	y_pos = y / SIZE_B;
	if (data->map[y_pos][x_pos] == '1')
		return (false);
	return (true);
}
