/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_elements_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:13:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	check_element_exists(t_map_data *data, char c)
{
	bool	flag;

	flag = false;
	if (c == 'N' && data->north)
		flag = true;
	else if (c == 'S' && data->south)
		flag = true;
	else if (c == 'W' && data->west)
		flag = true;
	else if (c == 'E' && data->east)
		flag = true;
	else if (c == 'F' && data->floor[0] >= 0)
	{
		printf("c: %c, floor[0]: %d\n", c, data->floor[0]);
		printf("flag == true now\n");
		flag = true;
	}
	else if (c == 'C' && data->ceiling[0] >= 0)
		flag = true;
	if (flag == true)
		return (error_message(X_UNKNOWN_ELEMENT));
	return (true);
}

char	*save_the_elements(t_map_data *data, int i, int j, bool *error)
{
	char	*str;

	if (!check_element_exists(data, data->file_splitted[i][0]))
	{
		*(error) = true;
		return (NULL);
	}
	if (data->file_splitted[i][j] != ' ' && data->file_splitted[i][j] != '\t')
	{
		print_error_message(X_UNKNOWN_ELEMENT);
		*(error) = true;
	}
	j += remove_whitespace(&data->file_splitted[i][j]);
	str = ft_strdup(&data->file_splitted[i][j]);
	if (!str)
	{
		print_error_message(X_MALLOC);
		*(error) = true;
	}
	return (str);
}

static char	*save_the_map(t_map_data *data, int i, int j, bool *error)
{
	char	*str;

	if (data->file_splitted[i][j] == '\n' \
		&& data->file_splitted[i + 1] != NULL)
	{
		print_error_message(X_EMPTY_LINES);
		*(error) = true;
		return (NULL);
	}
	str = ft_strdup(&data->file_splitted[i][j]);
	if (!str)
	{
		print_error_message(X_MALLOC);
		*(error) = true;
	}
	return (str);
}

static int	get_elements(t_map_data *data, int i, int j, bool *error)
{
	while (data->file_splitted[i] && !(*error))
	{
		if (data->file_splitted[i][0] != '\n')
			j = remove_whitespace(data->file_splitted[i]);
		if (!ft_strncmp(&data->file_splitted[i][j], "NO", 2))
			data->north = save_the_elements(data, i, j + 2, error);
		else if (!ft_strncmp(&data->file_splitted[i][j], "SO", 2))
			data->south = save_the_elements(data, i, j + 2, error);
		else if (!ft_strncmp(&data->file_splitted[i][j], "WE", 2))
			data->west = save_the_elements(data, i, j + 2, error);
		else if (!ft_strncmp(&data->file_splitted[i][j], "EA", 2))
			data->east = save_the_elements(data, i, j + 2, error);
		else if (!ft_strncmp(&data->file_splitted[i][j], "F", 1) \
			|| !ft_strncmp(&data->file_splitted[i][j], "C", 1))
			parse_colors(data, i, j, error);
		else if (!ft_strncmp(&data->file_splitted[i][j], "1", 1))
			break ;
		else if (data->file_splitted[i][0] != '\n')
		{
			print_error_message(X_UNKNOWN_ELEMENT);
			*(error) = true;
		}
		i++;
	}
	return (i);
}

char	*parse_file(t_map_data *data)
{
	int		i;
	int		j;
	bool	error;

	i = 0;
	j = 0;
	error = false;
	if (data->file_splitted[i])
		i = get_elements(data, i, j, &error);
	if (error)
		return (NULL);
	j = i;
	while (data->file_splitted[i])
		i++;
	data->map = malloc(sizeof(char *) * (i - j + 1));
	if (!data->map)
		return (print_error_message(X_MALLOC));
	i = 0;
	while (data->file_splitted[j] && !error)
		data->map[i++] = save_the_map(data, j++, 0, &error);
	if (error)
		return (NULL);
	data->map[i] = NULL;
	return ("Splitted");
}
