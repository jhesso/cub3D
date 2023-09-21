/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:10:37 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/21 19:15:22 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	open_texture_files(char *file)
{
	int	fd;

	if (!file)
		return (error_message(X_MALLOC));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_message(X_WRONG_TEXTURE_FILE));
	close(fd);
	return (true);

}


static bool	validate_texture(t_map_data *data)
{
	if (open_texture_files(data->north))
		return (false);
	if (open_texture_files(data->south))
		return (false);
	if (open_texture_files(data->west))
		return (false);
	if (open_texture_files(data->east))
		return (false);
	return (true);
}


bool	parse_elements(t_map_data *data)
{
	print_struct(data);
	validate_texture(data);
	return (true);
}
