/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/26 16:52:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_chars(char **map)
{
	int		row;
	int		col;
	bool	p_start;
	char	c;

	row = 0;
	p_start = false;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			c = map[row][col];
			if (c != '0' || c != '1' || c != 'N' || c != 'S' || c != 'E' ||\
				c != 'W')
				return (false);
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W' && !p_start)
				p_start = true;
			else
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	validate_map(char **map)
{
	if (!check_chars(map))
		return (error_messge(X_UNKNOWN_ELEMENT_MAP));
}
