/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:02:23 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/19 16:27:18 by dgerguri         ###   ########.fr       */
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

# include "../libft/includes/libft.h"
//# include "" should include the header file of the MLX library!

/******************************************************************************/
/*								Error Messages	 							  */
/******************************************************************************/

# define X_VALID_FILE "Error: The map is not a .cub file!\n"
# define X_OPEN_FILE "Error: Couldn't open the file!\n"
# define X_READ_FILE "Error: Couldn't read the file!\n"
# define X_MALLOC "Error: Malloc allocation has failed!\n"
# define X_UNKNOWN_ELEMENT "Error: Unknown element on the map!\n"

/******************************************************************************/
/*								Structs 									  */
/******************************************************************************/

typedef struct s_map_data
{
	//should add everything we need!
	char		**file_splitted;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceiling;
}				t_map_data;

/******************************************************************************/
/*								Functions									  */
/******************************************************************************/

int			print_error_message(char *message);

/*---------------------------------Init---------------------------------------*/

/* init */
void			map_data(t_map_data *data, char *map);

/* read_map */
void			read_map(t_map_data *data, char *file);

/* split_line */
char			**ft_split_line(char const *s);

/* parsing_map */
void			parse_file(t_map_data *data);

#endif
