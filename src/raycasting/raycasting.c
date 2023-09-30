/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:10:33 by dardangergu       #+#    #+#             */
/*   Updated: 2023/09/30 18:00:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(void *ptr)
{
	// (void)ptr;
	t_map_data *data = (t_map_data *)ptr;

	mlx_image_to_window(data->mlx_data->mlx, data->mlx_data->north, 0, 0);
}
