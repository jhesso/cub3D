/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:22:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/08 22:17:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

unsigned int	get_pixel(t_mlx_data *mlx, int x, int y, int dir)
{
	uint32_t	dst;
	mlx_image_t		*texture;

	// select correct image based on dir
	if (dir == NORTH)
		texture = mlx->north;
	else if (dir == EAST)
		texture = mlx->east;
	else if (dir == SOUTH)
		texture = mlx->south;
	else if (dir == WEST)
		texture = mlx->west;
	if ((uint32_t)x >= texture->width || x < 0 || (uint32_t)y >= texture->height || y < 0)
		return (get_rgba(255, 0, 0, 255)); // RED
	// get the pixel color value from the correct texture
	// for this I believe the textures should be in xpm format
	dst = get_rgba(0, 255, 0, 255); // just give color green to test
	return (dst);
}

float	fix_angle(float angle)
{
	if (angle < 0)
		angle += 360;
	else if (angle >= 360)
		angle -= 360;
	return (angle);
}

float	deg_to_rad(float degrees)
{
	float	radians;

	radians = degrees * (PI / 180);
	return (radians);
}

float	get_dist(t_float_v *player, t_float_v *wall_hit)
{
	float	a;
	float	b;
	float	c;

	a = player->x - wall_hit->x;
	b = player->y - wall_hit->y;
	c = sqrt((a * a) + (b * b));
	return (c);
}

int	get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
