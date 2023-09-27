/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:17:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/27 18:21:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// bool	check_edges(char **map)
// {
// 	int	row;
// 	int	col;

// 	row = 1;
// 	while (map[row])
// 	{
// 		col = 0;
// 		while (map[row][col])
// 			col++;
// 		if ((map[row][0] != '1' && map[row][0] != ' ') || \
// 			(map[row][col - 1] != '1' && map[row][col - 1] != ' '))
// 			return (false);
// 		row++;
// 	}
// 	return (true);
// }

bool	find_wall(char **map, t_vector pos)
{
	int		row;
	int		col;

	row = pos.y;
	col = pos.x;
	if (map[row][col + 1] == '\0' || map[row][col + 1] == ' ')
		return (false);
	if (map[row][col - 1] == '\0' || map[row][col - 1] == ' ')
		return (false);
	if (map[row + 1][col] == '\0' || map[row + 1][col] == ' ')
		return (false);
	if (map[row - 1][col] == '\0' || map[row - 1][col] == ' ')
		return (false);
	return (true);
}
