/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:57:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/18 16:22:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_filename(char *file)
{
	if (ft_strcmp(file + (ft_strlen(file) - 4), ".cub"))
		print_error_message(X_VALID_FILE);
	return (0);
}

static char	*ft_join(char *line, char *buf)
{
	char	*new_line;

	new_line = ft_strjoin(line, buf);
	if (!new_line)
		print_error_message(X_MALLOC);
	free(line);
	return (new_line);
}

static char	*read_file(int fd, char *buf, int flag, int ret)
{
	char	*line;

	while (ret > 0)
	{
		ret = read(fd, buf, BUFF);
		if (ret == -1)
		{
			free (buf);
			if (line)
				free(line);
			print_error_message(X_OPEN_FILE);
		}
		buf[ret] = '\0';
		if (flag)
			line = ft_join(line, buf); //if we do not exit in case malloc fails, we have to add a check here!
		else
		{
			line = ft_strdup(buf);
			if (!line)
				print_error_message(X_MALLOC);
			flag = 1;
		}
	}
	free(buf);
	return (line);
}

/*	read_map()
*	reads the given file and saves it into a char**
*/
void	read_map(t_map_data *data, char *file)
{
	int		fd;
	char	*line;
	char	*buf;

	validate_filename(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error_message(X_OPEN_FILE);
	buf = ft_calloc(BUFF + 1, sizeof(char));
	if (!buf)
		print_error_message(X_MALLOC);
	line = read_file(fd, buf, 0, 1);
	data->map = ft_split_line(line);
	free(line);
	close(file);
}
