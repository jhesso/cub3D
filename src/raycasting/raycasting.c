/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/09/30 18:21:55 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	raycasting(void *ptr)
{
	// (void)ptr;
	t_map_data *data = (t_map_data *)ptr;
	printf("starting: %d    %d\n", data->starting_pos.x, data->starting_pos.y);

	uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
	mlx_put_pixel(data->mlx_data->window, data->starting_pos.x, data->starting_pos.y, color);
	// mlx_image_to_window(data->mlx_data->mlx, data->mlx_data->north, 0, 0);
}
