/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/17 01:03:20 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "libft/get_next_line/get_next_line.h"
# define RESOLUTION_L 320
# define ROSOLUTION_H 200
# define BUFFERSIZ 1024
typedef struct s_game
{
    //------------------------------- for file
    int     total_lu;// de bytes lu par read pour
    int     index;// initaliser a after texture
    char	**TextureName;// FREEE OUBLIE PAS
    char    **split;// NE PAS OUBLIER DE FREE
    
    //-----------------------Chemins des textures
    char    *NO;
    char    *SO;//                   -> A NE SURTOUT PAS FREE CAR CES DES POINTEURS VERS MON SPLIT
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    //--------------------------------- MAP
    int map_height;
    //---------------------------------
    char    **map;// dans un tableau de tableau avec axe x et y
    
}           t_game;

typedef struct s_point
{
    int x;
    int y;
}               t_point;

/*
typedef struct s_img
{
    // data
};      t_img;

*/

/*
=================================
            PARSING -> adil
=================================
*/

int     main_parsing(char *file, t_game *data);

int     ft_line_empty(char *line);

void	ft_init_texture(t_game *d);

int     ft_file_empty(char *file);

int     chop_texture(t_game *data, int i, int j);// a appele avec i et j a 0 -> pour gain de place

int	    CheckAlreadyExist(t_game *data);

int	    ft_init_split(char *file, t_game *data);

int     parse_map(t_game *data);

int	limit_number_rgb(char *color);

#endif