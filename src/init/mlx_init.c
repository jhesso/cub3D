/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/28 16:44:05 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_mlx(t_map_data *data)
{
	if (!(data->mlx_data.mlx = mlx_init(1920, 1024, "cub3D", true)))
		return (error_message(X_UNKNOWN_ELEMENT_MAP));
	return (true);
}
