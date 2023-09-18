/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:43:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/18 16:28:04 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	init_map_data()
*	initializes variables of the map_data struct
*/
static void	init_variables(t_map_data *data)
{
	data->map = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->floor = 0;
	data->ceiling = 0;
}

void	map_data(t_map_data *data, char *map)
{
	init_variables(data);
	read_map(data, map);
	parse_map(data);

}
