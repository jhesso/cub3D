/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:13:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/19 17:06:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	remove_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return(i);
}

void	parse_file(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	print_string_arr(data->file_splitted);
	while (data->file_splitted[i])
	{
		while (data->file_splitted[i])
		{
			while (data->file_splitted[i] && data->file_splitted[i][0] == '\n')
				i++;
			j = remove_whitespace(data->file_splitted[i]);
			if (!ft_strncmp(data->file_splitted[i][j], "NO", 2))
				data->north = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "SO", 2))
				data->south = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "WE", 2))
				data->west = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "EA", 2))
				data->east = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "F", 1))
				data->floor = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "C", 1))
				data->ceiling = ft_strdup(data->file_splitted[i][j]);
			else if (!ft_strncmp(data->file_splitted[i][j], "1", 1) \
				&& data->file_splitted[i][0] != '\n')
					break;
			else if (data->file_splitted[i][0] != '\n')
				print_error_message(X_UNKNOWN_ELEMENT);
			i++;
		}

	}
}
