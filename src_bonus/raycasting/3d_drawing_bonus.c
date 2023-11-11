/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:37 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static float	clip_line_height(float to_clip)
{
	float	line_height;

	if (to_clip > HEIGHT_W)
		line_height = HEIGHT_W;
	else
		line_height = round((double)to_clip);
	return (line_height);
}

static t_float_v	get_texture_vec(t_float_v *hit, int dir, float y_step,
float line_size)
{
	t_float_v	texture;

	texture.y = 0;
	if (line_size > HEIGHT_W)
		texture.y = ((line_size - HEIGHT_W) / 2.0f) * y_step;
	if (dir == NORTH)
		texture.x = SIZE_B - 1 - (((int) hit->x) % SIZE_B);
	else if (dir == SOUTH)
		texture.x = ((int) hit->x) % SIZE_B;
	else if (dir == EAST)
		texture.x = SIZE_B - 1 - (((int) hit->y) % SIZE_B);
	else
		texture.x = ((int) hit->y) % SIZE_B;
	return (texture);
}

void	draw_walls(t_map_data *data, int x, t_ray *ray, int dir)
{
	float			line_height;
	unsigned int	pane_y_color[2];
	float			y_step;
	t_float_v		texture;
	int				drawn_count;

	line_height = SIZE_B * HEIGHT_W / ray->distance;
	y_step = SIZE_B / line_height;
	if (ray->shortest == 'v')
		texture = get_texture_vec(&ray->v_map, dir, y_step, line_height);
	else
		texture = get_texture_vec(&ray->h_map, dir, y_step, line_height);
	line_height = clip_line_height(line_height);
	pane_y_color[0] = (HEIGHT_W - line_height) / 2;
	drawn_count = 0;
	while (drawn_count++ < line_height)
	{
		pane_y_color[1] = get_pixel(data->mlx_data, texture.x, texture.y, dir);
		mlx_put_pixel(data->mlx_data->window, x, pane_y_color[0],
			pane_y_color[1]);
		pane_y_color[0]++;
		texture.y += y_step;
	}
}

static int	get_dir(t_ray *ray)
{
	if (ray->shortest == 'h' && (ray->angle >= 0 && ray->angle < 180))
		return (SOUTH);
	else if (ray->shortest == 'h' && (ray->angle >= 180 && ray->angle < 360))
		return (NORTH);
	else if (ray->shortest == 'v' && (ray->angle >= 90 && ray->angle < 270))
		return (EAST);
	else if (ray->shortest == 'v' && (ray->angle >= 270 || ray->angle < 90))
		return (WEST);
	return (-1);
}

void	draw_view(t_map_data *data, t_ray *ray, int x)
{
	int	dir;

	dir = get_dir(ray);
	draw_walls(data, x, ray, dir);
}
