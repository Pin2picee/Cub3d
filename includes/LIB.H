/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.H                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/10 15:29:33 by abelmoha         ###   ########.fr       */
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
    char    *NO;// =======> ce sont les chemins de texture
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;// couleur du sol
    char    *C;// couleur du plafond
    char    *R;
    int     total_lu;// de bytes lu par read pour
    //---------------------------------
    char    **map;// dans un tableau de tableau avec axe x et y
}           t_game;

typedef struct s_img
{
    /* data */
};      t_img;


#endif