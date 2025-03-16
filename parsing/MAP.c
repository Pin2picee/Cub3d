/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAP.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:30:34 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/16 18:30:47 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void    info_map(t_game *data)
{
    int j;
    
    j = 0;
    while (data->map[j] != NULL)
    {
        j++;
    }
    data->map_height = j;
    return ;
}
int     parse_bottom_top(t_game *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i][j] == ' ')
        j++;
    while (data->map[i][j])
    {
        if (data->map[i][j] != '1')
            return (1);
        j++;
    }
    j = 0;
    i = data->map_height - 1;
    while (data->map[i][j] == ' ')
        j++;
    while (data->map[i][j])
    {
        if (data->map[i][j] != '1')
            return (1);
        j++;
    }
    return (0);
}

int parse_side(t_game *data)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (data->map[i][j])
    {
        while (data->map[i][j] && data->map[i][j] == ' ')
            j++;
        if (data->map[i][j])
    }
}

int parse_map(t_game *data)
{
    /**
     * sa ne sert a rien de parser la map via les index
     * 
     * i faut faire un flood fill en partant du personnage pour verifier si on tombe sur un espace vide ou une bordure de map
     * 
     */
    info_map(data);
    if (parse_bottom_top(data))
        return (1);
    if (check_elements(data))
        return (1)
}