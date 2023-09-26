/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:59 by jhesso            #+#    #+#             */
/*   Updated: 2023/09/26 18:46:37 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (map[vec.y][vec.x] == '0')
				break ;
			vec.x++;
		}
		if (map[vec.y][vec.x] == '0')
			break ;
		vec.y++;
	}
	return (vec);
}
