/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:52:42 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/17 00:19:53 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/LIB.h"

/** Parametre du Programme
 * premier -> la map.cub
*/

/** Parsing Map
 * 
 * au dessus ->
 * Il y a des elements pour les textures NO SO WE EA qui peuvent etre separer par des lignes
 * milieu ->
 * Couleur du plafond ex :(C 225,30,0)
 * en dessous ->
 * 6 caracters seulement = 0, 1, (N,S,E,W)
 * ------------------------------
 * textures différentes (vous avez le choix) selon si les murs sont face nord, sud, est, ouest.
 * fermer entourer de murs,  les espaces doit etre sauter
 * 
 *          NO ./path_to_the_north_texture
            SO ./path_to_the_south_texture
            WE ./path_to_the_west_texture
            EA ./path_to_the_east_texture
            F 220,100,0
            C 225,30,0
            1111111111111111111111111
            1000000000110000000000001
            1011000001110000000000001
            1001000000000000000000001
            111111111011000001110000000000001
            100000000011000001110111111111111
            11110111111111011100000010001
            11110111111111011101010010001
            11000000110101011100000010001
            10000000000000001100000010001
            10000000000000001101010010001
            11000001110101011111011110N0111
            11110111 1110101 101111010001
            11111111 1111111 111111111111
 * le return = "Error\n"
*/

int main(int argc, char **argv)
{
    t_game data;
    
    (void)argc; 
    if (main_parsing(argv[1], &data))
    {
        printf("PROBLEM MAP :\n");
    }
    else
        printf("NO PROBLEM");
    return (0);
}

