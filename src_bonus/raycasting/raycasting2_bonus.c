/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:05:05 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 18:17:15 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_shortest(t_map_data *data, t_ray *ray)
{
	float	h_dist;
	float	v_dist;

	h_dist = get_dist(&data->pos, &ray->h_map);
	v_dist = get_dist(&data->pos, &ray->v_map);
	if (h_dist != 0.0f && (h_dist < v_dist || v_dist == 0.0f))
	{
		ray->shortest = 'h';
		ray->distance = h_dist * cos(deg_to_rad(ray->angle - data->angle));
	}
	else
	{
		ray->shortest = 'v';
		ray->distance = v_dist * cos(deg_to_rad(ray->angle - data->angle));
	}
}

void	check_hit_wall(t_map_data *data, t_float_v *grid, t_float_v *map,
t_float_v *offset)
{
	int	dof;

	dof = 0;
	if (map->x == data->pos.x && map->y == data->pos.x)
		return ;
	while (dof < 1000)
	{
		grid->x = (int)map->x / SIZE_B;
		grid->y = (int)map->y / SIZE_B;
		if (grid->y >= 0 && grid->x >= 0 && grid->x < data->map_w
			&& grid->y < data->map_h
			&& data->map[(int)grid->y][(int)grid->x] == '1')
			dof = 1000;
		else
		{
			map->x += offset->x;
			map->y += offset->y;
			dof++;
		}
	}
}

void	draw_floor_ceiling(t_map_data *data)
{
	t_vector	window;

	window.y = 0;
	while (window.y < HEIGHT_W / 2)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y,
				data->mlx_data->ceiling);
			window.x++;
		}
		window.y++;
	}
	while (window.y < HEIGHT_W)
	{
		window.x = 0;
		while (window.x < WIDTH_W)
		{
			mlx_put_pixel(data->mlx_data->window, window.x, window.y,
				data->mlx_data->floor);
			window.x++;
		}
		window.y++;
	}
}
