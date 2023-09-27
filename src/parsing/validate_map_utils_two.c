/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:17:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/27 12:31:28 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_edges(char **map)
{
	int	row;
	int	col;

	row = 1;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			col++;
		printf("map[%d][%d]: %c dec: %d\n", row, col, map[row][col - 1], (int)map[row][col - 1]);
		if ((map[row][0] != '1' && map[row][0] != ' ') || \
			(map[row][col - 1] != '1' && map[row][col - 1] != ' '))
			return (false);
		row++;
	}
	return (true);
}

bool	find_wall(char **map, t_vector pos)
{
	int		row;
	int		col;
	bool	ret;

	row = pos.y;
	col = pos.x;
	ret = false;
	while (col >= 0)
		if (map[row][col--] == '1')
			ret = true;
	if (!ret && col == 0)
		return (false);
	col = pos.x;
	while (row >= 0)
		if (map[row--][col] == '1')
			ret = true;
	if (!ret && row == 0)
		return (false);
	row = pos.y;
	while (map[row][col])
		if (map[row][col++] == '1')
			ret = true;
	if (!ret && map[row][col] == '\0')
		return (false);
	col = pos.x;
	while (map[row])
		if (map[row++][col] == '1')
			return (true);
	return (false);
}
