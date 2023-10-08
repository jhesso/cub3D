/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/10/08 09:29:29 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	starting_point(t_map_data *d, int row, int col, bool *p_start, char c) //move somewhere
{
	d->starting_pos.x = col * SIZE_B + ((SIZE_B - SIZE_P) / 2);
	d->starting_pos.y = row * SIZE_B + ((SIZE_B - SIZE_P) / 2);
	*(p_start) = true;
	if (c == 'N')
	{
		d->starting_angle.x = cosf(270 * M_PI / 180.0);
		d->starting_angle.y = sinf(270 * M_PI / 180.0);
	}
	else if (c == 'S')
	{
		d->starting_angle.x = cosf(90 * M_PI / 180.0);
		d->starting_angle.y = sinf(90 * M_PI / 180.0);
	}
	else if (c == 'W')
	{
		d->starting_angle.x = cosf(180 * M_PI / 180.0);
		d->starting_angle.y = sinf(180 * M_PI / 180.0);
	}
	else if (c == 'E')
	{
		d->starting_angle.x = cosf(360 * M_PI / 180.0);
		d->starting_angle.y = sinf(360 * M_PI / 180.0);
	}
}

static bool	check_chars(t_map_data *data, int row, int col, bool p_start)
{
	char	c;

	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			c = data->map[row][col];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && \
				c != 'W' && c != ' ')
				return (error_message(X_UNKNOWN_ELEMENT_MAP));
			if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && !p_start)
				starting_point(data, row, col, &p_start, c);
			else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return (error_message(X_MULTIPLE_S_POINTS));
			if (c == '\t' || c == '\v' || c == '\f' || c == '\r')
				return (error_message(X_UNKNOWN_ELEMENT_MAP));
			col++;
		}
		row++;
	}
	if (!p_start)
		return (error_message(X_S_P_MISSING));
	return (true);
}

static bool	check_first_and_last(char **map)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (map[row][col])
	{
		c = map[row][col];
		if (c != '1' && c != ' ')
			return (false);
		col++;
	}
	while (map[row + 1])
		row++;
	row--;
	col = 0;
	while (map[row][col])
	{
		c = map[row][col];
		if (c != '1' && c != ' ')
			return (false);
		col++;
	}
	return (true);
}

static bool	flood_fill(char **map, t_vector pos, bool *stop)
{
	if (map[pos.y][pos.x] == '\0' || (*stop))
		return (false);
	if (map[pos.y][pos.x] == '1')
		return (true);
	if (find_wall(map, pos))
		map[pos.y][pos.x] = '1';
	else
	{
		*(stop) = true;
		return (false);
	}
	flood_fill(map, (t_vector){pos.x + 1, pos.y}, stop);
	flood_fill(map, (t_vector){pos.x - 1, pos.y}, stop);
	flood_fill(map, (t_vector){pos.x, pos.y + 1}, stop);
	flood_fill(map, (t_vector){pos.x, pos.y - 1}, stop);
	return (false);
}

static bool	check_walls(t_map_data *data, bool stop)
{
	char		**tmp_map;
	t_vector	last_point;
	t_vector	point;

	if (!check_first_and_last(data->map))
		return (false);
	remove_newline(data->map);
	// if (!check_edges(map))
	// 	return (false);
	tmp_map = duplicate_map(data->map);
	last_point = get_last_point(tmp_map);
	point = find_empty_space(tmp_map);
	while (true)
	{
		if ((point.y == last_point.y && point.x == last_point.x) || stop)
			break ;
		flood_fill(tmp_map, point, &stop);
		point = find_empty_space(tmp_map);
	}
	if (!map_filled(tmp_map))
		return (false);
	free_array(tmp_map);
	return (true);
}

bool	validate_map(t_map_data *data)
{
	if (!check_chars(data, 0, 0, false))
		return (false);
	if (!check_walls(data, false))
		return (error_message(X_MAP_NOT_CLOSED));
	return (true);
}
