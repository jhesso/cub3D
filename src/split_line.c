/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:57:35 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/15 20:00:38 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_amount_of_words(char const *s, char c)
{
	int	amount;
	int	flag;
	int	i;

	amount = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			amount++;
			while (s[i + 1] == c && s[i + 1] != '\0')
			{
				amount++;
				i++;
			}
		}
		else if (s[i] != c)
		{
			amount++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (amount);
}

static	int	get_word_len(char const *s, char c, int start)
{
	int	i;
	int	len;

	i = start;
	len = 0;
	// while (s[i] == c)
	// 	i++;
	if (s[i] == c)
		len = 1;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	// printf("word_len: %d\n", len);
	return (len);
}

static char	**free_allocated_strings(char **ret, int row)
{
	while (row >= 0)
		free(ret[row--]);
	free(ret);
	return (NULL);
}

/*	ft_split()
*	splits given string s based on the delimiter char c into a 2d array of
*	strings
*	returns said 2d arr of strings or NULL if failed
*	the caller is required to handle freeing the array after done using
*/
char	**ft_split_line(char const *s, char c)
{
	char			**ret;
	unsigned int	i;
	unsigned int	row;
	unsigned int	word_count;

	if (s == NULL)
		return (NULL);
	word_count = get_amount_of_words(s, c);
	printf("%d\n", word_count);
	ret = malloc(sizeof(char *) * (word_count + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	row = -1;
	// printf("%s\n", s);
	while (++row < word_count)
	{

	}
	ret[row] = NULL;
	return (ret);
}
