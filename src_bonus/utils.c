/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:26:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**free_array(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
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

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
