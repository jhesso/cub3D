/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:36:06 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_angle(t_map_data *data, float angle)
{
	data->angle = angle;
	data->dir.x = cos(angle * M_PI / 180);
	data->dir.y = -sin(angle * M_PI / 180);
}

void	starting_point(t_map_data *d, t_vector pos, bool *p_start, char c)
{
	d->pos.x = pos.x * (float)SIZE_B + (((float)SIZE_B - (float)SIZE_P) / 2);
	d->pos.y = pos.y * (float)SIZE_B + (((float)SIZE_B - (float)SIZE_P) / 2);
	*(p_start) = true;
	if (c == 'N')
		get_angle(d, 90.0f);
	else if (c == 'S')
		get_angle(d, 270.0f);
	else if (c == 'W')
		get_angle(d, 180.0f);
	else if (c == 'E')
		get_angle(d, 0.0f);
}
