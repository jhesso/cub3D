/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:19:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/26 18:10:08 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*print_error_message(char *message)
{
	ft_printf(2, "%s", message);
	// return(false);
	return (NULL);
}


bool	error_message(char *message)
{
	ft_printf(2, "%s", message);
	return (false);
}

char	**free_array(char **ret) //temperory position
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
