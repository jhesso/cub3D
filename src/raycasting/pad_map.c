/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:01:02 by jhesso            #+#    #+#             */
/*   Updated: 2023/11/11 02:30:42 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**alloc(t_map_data *data)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (data->map_h + 1));
	if (!new)
	{
		print_error_message(X_MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < data->map_h)
	{
		new[i] = malloc(sizeof(char) * data->map_w + 1);
		if (!new[i])
		{
			print_error_message(X_MALLOC);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

bool	pad_map(t_map_data *data)
{
	char	**new;
	int		i;
	int		j;

	new = alloc(data);
	if (!new)
		return (false);
	i = 0;
	while (i < data->map_h && new[i])
	{
		ft_strlcpy(new[i], data->map[i], (ft_strlen(data->map[i]) + 1));
		j = ft_strlen(data->map[i]);
		while (j < data->map_w)
		{
			new[i][j] = '1';
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	free_array(data->map);
	data->map = new;
	return (true);
}
