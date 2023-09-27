/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/27 19:03:07 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_chars(char **map, int row, int col)
{
	bool	p_start;
	char	c;

	p_start = false;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			c = map[row][col];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' &&\
				c != 'W' && c != ' ')
				return (false);
			if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && !p_start)
				p_start = true;
			else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return (false);
			if (c == '\t' || c == '\v' || c == '\f' || c == '\r')
				return (false);
			col++;
		}
		row++;
	}
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
	// printf("flood_fill: pos.y: %d, pos.x: %d\n", pos.y, pos.x);
	// print_string_arr(map);
	if (map[pos.y][pos.x] == '\0' || !(*stop))
		return (false);
	if (map[pos.y][pos.x] == '1')
		return (true);
	if (find_wall(map, pos))
		map[pos.y][pos.x] = '1';
	else
	{
		*(stop) = false;
		return (false);
	}
	flood_fill(map, (t_vector){pos.x + 1, pos.y}, stop);
	flood_fill(map, (t_vector){pos.x - 1, pos.y}, stop);
	flood_fill(map, (t_vector){pos.x, pos.y + 1}, stop);
	flood_fill(map, (t_vector){pos.x, pos.y - 1}, stop);
	return (false);
}

static bool	check_walls(char **map)
{
	char		**tmp_map;
	t_vector	last_point;
	t_vector	point;
	bool		surrounded;
	bool		stop = true;

	if (!check_first_and_last(map))
		return (false);
	remove_newline(map);
	// if (!check_edges(map))
	// 	return (false);
	tmp_map = duplicate_map(map);
	// print_string_arr(tmp_map);
	last_point = get_last_point(tmp_map);
	surrounded = false;
	point = find_empty_space(tmp_map);
	while (true)
	{
		if (point.y == last_point.y && point.x == last_point.x)
			break;
		surrounded = flood_fill(tmp_map, point, &stop);
		// printf("%d\n", stop);/
		if (!stop)
			break ;
		point = find_empty_space(tmp_map);
	}
	if (!map_filled(tmp_map))
		return (false);
	free_array(tmp_map);
	return (true);
}

bool	validate_map(char **map)
{
	if (!check_chars(map, 0, 0))
		return (error_message(X_UNKNOWN_ELEMENT_MAP));
	if (!check_walls(map))
		return (error_message(X_MAP_NOT_CLOSED));
	return (true);
}
