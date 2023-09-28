/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:17:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/28 12:30:54 by dgerguri         ###   ########.fr       */
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
