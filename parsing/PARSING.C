/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.C                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/06 17:30:08 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/LIB.H"

/*
===========================================================
                        parsing map
                        stockage data

===========================================================
*/

int check_extension(char *file)
{
    char *extension;
    
    extension = ft_strchr(file, '.');
    if (!extension || ft_strcmp(extension, "cub"))// si pas de . ou extension differente
    {
        return (1);
    }
    return (0);
}

int main_parsing(char *file, t_game *data)
{
    if (check_extension(file))
        return (1);
    else if ()
}