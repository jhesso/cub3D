/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:43:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/26 18:23:06 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	init_map_data()
*	initializes variables of the map_data struct
*/
static void	init_variables(t_map_data *data)
{
	int	i;

	i = 0;
	data->file_splitted = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->floor = malloc(sizeof(int) * 3);
	data->ceiling = malloc(sizeof(int) * 3);
	data->map = NULL;
}

bool	map_data(t_map_data *data, char *map)
{
	init_variables(data);
	if (!read_map(data, map))
		return (false);
	if (!parse_file(data))
		return (false);
	if (!validate_elements(data))
		return (false);
	return (true);
}
