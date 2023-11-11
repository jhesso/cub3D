/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:57:35 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/11 17:41:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	count_lines(char const *s)
{
	int	amount;
	int	i;

	amount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			amount++;
			while (s[i + 1] == '\n' && s[i + 1])
			{
				amount++;
				i++;
			}
		}
		else if (s[i] != '\n')
		{
			amount++;
			while (s[i] != '\n' && s[i + 1])
				i++;
		}
		i++;
	}
	return (amount + 1);
}

static	int	get_line_len(char const *s, int start)
{
	int	i;
	int	len;

	i = start;
	len = 0;
	if (s[i] == '\n')
		len = 1;
	while (s[i] && s[i] != '\n')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split_line(char const *s)
{
	char			**ret;
	unsigned int	i;
	unsigned int	row;
	unsigned int	line_count;

	if (s == NULL)
		return (NULL);
	line_count = count_lines(s);
	ret = malloc(sizeof(char *) * (line_count + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	row = -1;
	while (++row < line_count)
	{
		if (s[i] == '\n' && s[i + 1] != '\n' && i != 0)
			i++;
		ret[row] = ft_substr(s, i, get_line_len(s, i));
		if (ret[row] == NULL)
			return (free_array(ret));
		i = i + get_line_len(s, i);
	}
	ret[row] = NULL;
	return (ret);
}
