/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:51 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/28 19:59:52 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_map_data *data)
{
	if (data->file_splitted)
		free_array(data->file_splitted);
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		free_array(data->map);
}
