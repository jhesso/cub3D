/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:26:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/12 17:13:44 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	remove_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

void	get_map_size(t_map_data *data)
{
	int	i;
	int	w;

	i = 0;
	while (data->map[i])
	{
		w = ft_strlen(data->map[i]);
		if (w > data->map_w)
			data->map_w = w;
		i++;
	}
	data->map_h = i;
}
