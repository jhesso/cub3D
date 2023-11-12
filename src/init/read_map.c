/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:57:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/12 15:13:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*validate_filename(char *file)
{
	if (ft_strcmp(file + (ft_strlen(file) - 4), ".cub"))
		return (print_error_message(X_VALID_FILE));
	return ("Valid");
}

static char	*ft_join(char *line, char *buf)
{
	char	*new_line;

	new_line = ft_strjoin(line, buf);
	if (!new_line)
		return (print_error_message(X_MALLOC));
	free(line);
	return (new_line);
}

static char	*read_fail(char *buf, char *line)
{
	free (buf);
	if (line)
		free(line);
	return (print_error_message(X_READ_FILE));
}

static char	*read_file(int fd, char *buf, int flag, int ret)
{
	char	*line;

	line = NULL;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF);
		if (ret == -1)
			return (read_fail(buf, line));
		buf[ret] = '\0';
		if (flag)
		{
			line = ft_join(line, buf);
			if (!line)
				return (print_error_message(X_MALLOC));
		}
		else
		{
			line = ft_strdup(buf);
			if (!line)
				return (print_error_message(X_MALLOC));
			flag = 1;
		}
	}
	free(buf);
	return (line);
}

/*	read_map()
*	reads the given file and saves it into a char**
*/
bool	read_map(t_map_data *data, char *file)
{
	int		fd;
	char	*line;
	char	*buf;

	if (!validate_filename(file))
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error_message(X_OPEN_FILE));
	buf = ft_calloc(BUFF + 1, sizeof(char));
	if (!buf)
		return (print_error_message(X_MALLOC));
	line = read_file(fd, buf, 0, 1);
	close(fd);
	if (!line)
		return (false);
	data->file_splitted = ft_split_line(line);
	free(line);
	if (!data->file_splitted)
		return (print_error_message(X_MALLOC));
	return (true);
}
