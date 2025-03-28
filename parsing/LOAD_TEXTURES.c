/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LOAD_TEXTURES.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:50 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 16:56:08 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void	load_texture(t_game *data)
{
	data->no_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->no,
			&data->no_t.width, &data->no_t.height);
	data->no_t.data = mlx_get_data_addr(data->no_t.img, &data->no_t.bpp,
			&data->no_t.size_line, &data->no_t.endian);
	data->so_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->so,
			&data->so_t.width, &data->so_t.height);
	data->so_t.data = mlx_get_data_addr(data->so_t.img, &data->so_t.bpp,
			&data->so_t.size_line, &data->so_t.endian);
	data->we_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->we,
			&data->we_t.width, &data->we_t.height);
	data->we_t.data = mlx_get_data_addr(data->we_t.img, &data->we_t.bpp,
			&data->we_t.size_line, &data->we_t.endian);
	data->ea_t.img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea,
			&data->ea_t.width, &data->ea_t.height);
	data->ea_t.data = mlx_get_data_addr(data->ea_t.img, &data->ea_t.bpp,
			&data->ea_t.size_line, &data->ea_t.endian);
	data->tab_img[0] = &data->we_t;
	data->tab_img[1] = &data->ea_t;
	data->tab_img[2] = &data->no_t;
	data->tab_img[3] = &data->so_t;
}
