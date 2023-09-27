/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/27 12:04:12 by jhesso           ###   ########.fr       */
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

static bool	flood_fill(char **map, t_vector pos)
{
	printf("flood_fill: pos.y: %d, pos.x: %d\n", pos.y, pos.x);
	if (map[pos.y][pos.x] == '\0')
		return (false);
	if (map[pos.y][pos.x] == '1')
		return (true);
	// if (map[pos.y][pos.x] != ' ')
	// 	map[pos.y][pos.x] = '1';
	if (find_wall(map, pos))
		map[pos.y][pos.x] = '1';
	flood_fill(map, (t_vector){pos.x + 1, pos.y});
	flood_fill(map, (t_vector){pos.x - 1, pos.y});
	flood_fill(map, (t_vector){pos.x, pos.y + 1});
	flood_fill(map, (t_vector){pos.x, pos.y - 1});
	if (map_filled(map))
		return (true);
	return (false);
}

static bool	check_walls(char **map)
{
	char		**tmp_map;
	t_vector	last_point;
	t_vector	point;
	bool		surrounded;

	if (!check_first_and_last(map))
		return (false);
	remove_newline(map);
	if (!check_edges(map))
		return (false);
	tmp_map = duplicate_map(map);
	print_string_arr(tmp_map);
	last_point = get_last_point(tmp_map);
	surrounded = false;
	point = find_empty_space(tmp_map);
	printf("last_point.y: %d last_point.x: %d\n", last_point.y, last_point.x);
	while (true)
	{
		if (point.y == last_point.y && point.x == last_point.x)
			break;
		surrounded = flood_fill(tmp_map, point);
		printf("\n\n------AFTER FLOODFILL-------\n\n");
		print_string_arr(tmp_map);
		printf("\n--------------------------------\n\n");
		point = find_empty_space(tmp_map);
		printf("next empty spot: row: %d col: %d\n", point.y, point.x);
	}
	printf("done with floodfill\n");
	printf("\n\n------AFTER FLOODFILL-------\n\n");
	print_string_arr(tmp_map);
	printf("\n--------------------------------\n\n");
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
