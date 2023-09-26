/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/26 18:47:30 by jhesso           ###   ########.fr       */
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
	}
	while (map[row + 1])
		row++;
	col = 0;
	while (map[row][col])
	{
		c = map[row][col];
		if (c != '1' && c != ' ')
			return (false);
	}
	return (true);
}

static bool	flood_fill(char **map, t_vector pos)
{
	int	row;
	int	col;

	row = pos.y;
	col = pos.x;
	while (row >= 0 && map[row][col] != '1')
		row--;
	if (row == 0 && map[row][col] != '1')
		return (false);
	while (col >= 0 && map[row][col] != '1')
		col--;
	if (col == 0 && map[row][col] != '1')
		return (false);
}

static bool	check_walls(char **map)
{
	char	**tmp_map;

	if (!check_first_and_last(map))
		return (false);
	tmp_map = duplicate_map(map);
	if (!flood_fill(tmp_map, find_empty_space(map)))
		return (false);
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
