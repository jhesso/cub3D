/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:02:23 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/26 18:50:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFF
#  define BUFF 42
# endif

/******************************************************************************/
/*								Includes  									  */
/******************************************************************************/

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h> //read
# include <sys/uio.h> //read
# include <stdbool.h>

# include "../libft/includes/libft.h"
//# include "" should include the header file of the MLX library!

/******************************************************************************/
/*								Error Messages	 							  */
/******************************************************************************/

# define X_VALID_ARGUMENTS "Error: Invalid number of arguments!\n"
# define X_VALID_FILE "Error: The map is not a .cub file!\n"
# define X_OPEN_FILE "Error: Couldn't open the file!\n"
# define X_READ_FILE "Error: Couldn't read the file!\n"
# define X_MALLOC "Error: Malloc allocation has failed!\n"
# define X_UNKNOWN_ELEMENT "Error: Unknown element on the file!\n"
# define X_UNKNOWN_ELEMENT_MAP "Error: Unknown element on the map!\n"
# define X_MISSING_TEXTURE "Error: Texture file is missing!\n"
# define X_MISSING_COLOR "Error: Color is missing!\n"
# define X_WRONG_TEXTURE_FILE "Error: Wrong texture file!\n"
# define X_WRONG_COLOR_VALUE "Error: Wrong color value!\n"
# define X_EMPTY_LINES "Error: Map has empty lines!\n"
# define X_MAP_NOT_CLOSED "Error: Map not closed with walls!\n"

/******************************************************************************/
/*								Structs 									  */
/******************************************************************************/

typedef struct s_map_data
{
	char		**file_splitted;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			*floor;
	int			*ceiling;
	char		**map;
}				t_map_data;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/******************************************************************************/
/*								Functions									  */
/******************************************************************************/

/* error */
char		*print_error_message(char *message);
bool		error_message(char *message);

char		**free_array(char **ret); //temperory position

/* cleanup */
void		cleanup(t_map_data *data);

/*---------------------------------Init---------------------------------------*/

/* init */
bool		map_data(t_map_data *data, char *map);

/* read_map */
bool		read_map(t_map_data *data, char *file);

/* split_line */
char		**ft_split_line(char const *s);

/*---------------------------------Parsing------------------------------------*/

/* split_elements&map */
char		*parse_file(t_map_data *data);
char		*save_the_elements(t_map_data *data, int i, int j, bool *error);

/* validate_elements */
bool		validate_elements(t_map_data *data);

/* parse_colors */
void		parse_colors(t_map_data *data, int i, int j, bool *error);

/* validate_map */
bool		validate_map(char **map);

/* validate_map_utils */
t_vector	find_empty_space(char **map);
char		**duplicate_map(char **map);

/* TEMPORARY IN MAIN*/
void		print_struct(t_map_data *data);

#endif
