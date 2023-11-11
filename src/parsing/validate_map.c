/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 03:45:58 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				starting_point(data, (t_vector){col, row}, &p_start, c);
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
