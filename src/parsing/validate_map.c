/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/26 19:36:18 by jhesso           ###   ########.fr       */
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
				c != 'W')
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

// static bool	flood_fill(char **map, t_vector pos)
// {
// 	int	row;
// 	int	col;

// 	row = pos.y;
// 	col = pos.x;
// 	while (row >= 0)
// 	{
// 		if (map[row][col] == '1')
// 			return (true);
// 		row--;
// 	}
// 	while (col >= 0)
// 	{
// 		if (map[row][col] == '1')
// 			return (true);
// 		col--;
// 	}
// 	return (false);
// }

static bool	flood_fill(char **map, t_vector pos)
{
	if (map[pos.y][pos.x] == '1')
		return (true);
	map[pos.y][pos.x] = '1';
	flood_fill(map, (t_vector){pos.x + 1, pos.y});
	flood_fill(map, (t_vector){pos.x - 1, pos.y});
	flood_fill(map, (t_vector){pos.x, pos.y + 1});
	flood_fill(map, (t_vector){pos.x, pos.y - 1});
	return (false);
}

static bool	check_walls(char **map)
{
	char		**tmp_map;
	t_vector	last_point;
	t_vector	point;
	bool		surrounded;

	printf("LUL\n");
	if (!check_first_and_last(map))
		return (false);
	tmp_map = duplicate_map(map);
	print_string_arr(tmp_map);
	last_point = get_last_point(tmp_map);
	surrounded = false;
	point = find_empty_space(tmp_map);
	while (point.y <= last_point.y && point.x <= last_point.x)
	{
		surrounded = flood_fill(tmp_map, point);
		point = find_empty_space(tmp_map);
	}
	if (!surrounded)
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
