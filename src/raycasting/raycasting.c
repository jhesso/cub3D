/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/10/02 16:10:23 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// void	draw_box(t_map_data *data, t_vector pos, t_vector size, uint32_t *color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < size.y)
// 	{
// 		x = 0;
// 		while (x < size.x)
// 		{
// 			mlx_put_pixel(data->mlx_data->window, pos.x + x, pos.y + y, *color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	static_draw_wall(t_map_data *data, t_vector cord, char type, uint32_t *color)
// {
// 	if (type == '1')
// 		draw_box(data,
// 			(t_vector){cord.x * 64,  cord.y * 64}, (t_vector){cord.x * 64,  cord.y * 64}, color);
// 	else if (type == 'O')
// 		draw_box(data,
// 			(t_vector){cord.x * 64,  cord.y * 64}, (t_vector){cord.x * 64,  cord.y * 64}, color);
// }

// static void	draw_walls(t_map_data *data, uint32_t *color)
// {
// 	t_vector 	cord;

// 	cord.y = 0;
// 	cord.x =  0;
// 	while (data->map[cord.y][cord.x])
// 	{
// 		cord.x = 0;
// 		while (data->map[cord.y][cord.x])
// 		{
// 			static_draw_wall(data, cord, data->map[cord.y][cord.x], color);
// 			cord.x++;
// 		}
// 		cord.y++;
// 	}
// }

void	raycasting(void *ptr)
{
	// (void)ptr;
	t_map_data *data = (t_map_data *)ptr;
	// printf("starting: %d    %d\n", 1920 - (data->starting_pos.x * 64), 1024 - (data->starting_pos.y * 64));

	t_vector cord;
	uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);

	while (cord.x < 1920)
	{
		cord.y = 0;
		while (cord.y < 1024)
		{
			mlx_put_pixel(data->mlx_data->window, cord.x, cord.y, color);
			cord.y++;
		}
		cord.x++;
	}
	// draw_walls(data, &color);
}

