/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:59 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/27 11:15:42 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_filled(char **map)
{
	char	c;
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			c = map[row][col];
			if (c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' &&\
				c != ' ')
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

void	remove_newline(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i][0] == '\0')
	{
		free(map[i]);
		map[i] = NULL;
	}
}

t_vector	get_last_point(char **map)
{
	t_vector	ret;
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (map[row])
		row++;
	row--;
	while (map[row][col])
		col++;
	col--;
	ret.y = row;
	ret.x = col;
	return (ret);
}

char	**duplicate_map(char **map)
{
	char	**ret;
	int		i;

	i = 0;
	while (map[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = NULL;
	i = 0;
	while (map[i])
	{
		ret[i] = ft_strdup(map[i]);
		i++;
	}
	return (ret);
}

t_vector find_empty_space(char **map)
{
	t_vector	vec;

	vec.y = 1;
	while (map[vec.y])
	{
		vec.x = 0;
		while (map[vec.y][vec.x])
		{
			if (map[vec.y][vec.x] == '0' || map[vec.y][vec.x] == 'N' ||\
				map[vec.y][vec.x] == 'S' || map[vec.y][vec.x] == 'E'||\
				map[vec.y][vec.x] == 'W')
				break ;
			vec.x++;
		}
		if (map[vec.y][vec.x] == '0' || map[vec.y][vec.x] == 'N' ||\
			map[vec.y][vec.x] == 'S' || map[vec.y][vec.x] == 'E'||\
			map[vec.y][vec.x] == 'W')
			break ;
		vec.y++;
	}
	if (!map[vec.y])
		vec.y--;
	if (!map[vec.y][vec.x])
		vec.x--;
	return (vec);
}
