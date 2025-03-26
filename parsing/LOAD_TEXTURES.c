/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LOAD_TEXTURES.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:50 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/26 13:38:06 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void    load_texture(t_game *data)
{
    data->NO_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->NO, &data->NO_t.width, &data->NO_t.height);
    data->NO_t.data = mlx_get_data_addr(data->NO_t.img, &data->NO_t.bpp, &data->NO_t.size_line, &data->NO_t.endian);
    
    data->SO_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->SO, &data->SO_t.width, &data->SO_t.height);
    data->SO_t.data = mlx_get_data_addr(data->SO_t.img, &data->SO_t.bpp, &data->SO_t.size_line, &data->SO_t.endian);
    
    data->WE_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->WE, &data->WE_t.width, &data->WE_t.height);
    data->WE_t.data = mlx_get_data_addr(data->WE_t.img, &data->WE_t.bpp, &data->WE_t.size_line, &data->WE_t.endian);
    
    data->EA_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->EA, &data->EA_t.width, &data->EA_t.height);
    data->EA_t.data = mlx_get_data_addr(data->EA_t.img, &data->EA_t.bpp, &data->EA_t.size_line, &data->EA_t.endian);
    data->tab_img[0] = &data->WE_t;
    data->tab_img[1] = &data->EA_t;
    data->tab_img[2] = &data->NO_t;
    data->tab_img[3] = &data->NO_t;
}
