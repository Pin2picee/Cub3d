/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/12 17:01:13 by abelmoha         ###   ########.fr       */
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

typedef struct s_game
{
    //------------------------------- for file
    char **texture;
    int     total_lu;// de bytes lu par read pour
    char	**TextureName;
    //---------------------------------
    char    **map;// dans un tableau de tableau avec axe x et y
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
void	ft_init_texture(t_game *d);
int     ft_file_empty(char *file);
void    chop_texture(char *file, t_game *d, int fd, int i);
int     CheckAlreadyExist(char *file, char **TextureName);

#endif