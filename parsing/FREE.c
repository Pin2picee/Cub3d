/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FREE.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:23:52 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/18 18:23:52 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return ;
    while (tab[i] != NULL)
        free(tab[i++]);
    free(tab);
    return ;
}


void    free_data(t_game *data)
{
    if (data->TextureName)
        free_tab(data->TextureName);
    // on free la map via le split de ma data car j'ai fait un pointeur vers le debut de la map
    if (data->split)
        free_tab(data->split);
    // il faut free tous le coter mlx pour le render
}
