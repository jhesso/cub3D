/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:51 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/26 18:20:28 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_map_data *data)
{
	int	i;

	i = 0;
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
