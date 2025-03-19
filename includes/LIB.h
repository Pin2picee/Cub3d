/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/19 14:49:11 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "libft/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# define RESOLUTION_L 2500
# define RESOLUTION_H 1080
# define BUFFERSIZ 1024
# define NAME_WINDOW "Cub3d"
# define rouge 0xFFFF0000
# define verte 0xFF00FF00
# define bleu 0xFF0000FF
typedef struct s_point
{
    double x;
    double y;
}               t_point;

typedef struct s_img
{
    char    *data;
    void    *img;
    int     bpp;
    int     endian;
    int     size_line;
    
}               t_img;

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
    int flags;
    //---------------------------------
    char    **map;// dans un tableau de tableau avec axe x et y
    t_point pos_player;
    //-------------------------------- RENDER

    
    void    *mlx_ptr;
    void    *mlx_window;
    t_img   frame;
}           t_game;


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

int ft_init_texture(t_game *d);

int     ft_file_empty(char *file);

int	chop_texture(t_game *data, int i, int j, int fd);// a appele avec i et j a 0 -> pour gain de place

int	    CheckAlreadyExist(t_game *data);

int	ft_init_split(char *file, t_game *data, int fd, int lettre_lu);

int     parse_map(t_game *data);

int	limit_number_rgb(char *color);

int	ft_position(t_game *game);

char	**copy_map(char **map, int height);// la meme que celui de so_long

/*
=============================================
                FREE
=============================================
*/

void    free_data(t_game *data);
void    free_tab(char **tab);


/*
============================================
            RENDER -> RECASTING
============================================
*/

int init_my_mlx(t_game *data);


#endif