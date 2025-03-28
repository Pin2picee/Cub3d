/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 18:06:19 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int	check_rgb_f(t_game *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->split[i] && ft_strncmp(d->split[i], d->texture_name[5], 2))
		i++;
	while (d->split[i][j] && d->split[i][j] >= 'A' && d->split[i][j] <= 'Z')
		j++;
	while (d->split[i][j] && d->split[i][j] == ' ')
		j++;
	d->floor = ft_get_color_key(d->split[i] + j);
	if (limit_number_rgb(d->split[i] + j, 0, 0, 0))
		return (1);
	if (no_number(d->split[i] + j))
		return (1);
	while (d->split[i][j])
	{
		if ((d->split[i][j] < '0' || d->split[i][j] > '9')
			&& d->split[i][j] != ',')
			return (1);
		j++;
	}
	return (0);
}

int	check_rgb_c(t_game *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->split[i] && ft_strncmp(d->split[i], d->texture_name[4], 2))
		i++;
	while (d->split[i][j] && d->split[i][j] >= 'A' && d->split[i][j] <= 'Z')
		j++;
	while (d->split[i][j] && d->split[i][j] == ' ')
		j++;
	d->ceiling = ft_get_color_key(d->split[i] + j);
	if (limit_number_rgb(d->split[i] + j, 0, 0, 0))
		return (1);
	if (no_number(d->split[i] + j))
		return (1);
	while (d->split[i][j])
	{
		if ((d->split[i][j] < '0' || d->split[i][j] > '9')
			&& d->split[i][j] != ',')
			return (1);
		j++;
	}
	return (0);
}

int	chop_help(t_game *d, int i, int j, int fd)
{
	char	buffer[1];

	if ((fd < 0 || 0 > read(fd, buffer, sizeof(buffer)))
		&& (ft_strncmp(d->split[i], d->texture_name[4], 2)
			&& ft_strncmp(d->split[i], d->texture_name[5], 2)))
		return (1);
	if (!ft_strncmp(d->split[i], d->texture_name[0],
			ft_strlen(d->texture_name[0])))
		d->no = d->split[i] + j;
	else if (!ft_strncmp(d->split[i], d->texture_name[1],
			ft_strlen(d->texture_name[1])))
		d->so = d->split[i] + j;
	else if (!ft_strncmp(d->split[i], d->texture_name[2],
			ft_strlen(d->texture_name[2])))
		d->we = d->split[i] + j;
	else if (!ft_strncmp(d->split[i], d->texture_name[3],
			ft_strlen(d->texture_name[3])))
		d->ea = d->split[i] + j;
	else if (!ft_strncmp(d->split[i], d->texture_name[4],
			ft_strlen(d->texture_name[4])))
		d->c = d->split[i] + j;
	else if (!ft_strncmp(d->split[i], d->texture_name[5],
			ft_strlen(d->texture_name[5])))
		d->f = d->split[i] + j;
	return (0);
}

int	chop_texture(t_game *d, int i, int j, int fd)
{
	while (d->split[++i] && i < d->index)
	{
		j = 0;
		while (d->split[i][j] && d->split[i][j] >= 'A' && d->split[i][j] <= 'Z')
			j++;
		while (d->split[i][j] && d->split[i][j] == ' ')
			j++;
		fd = open(d->split[i] + j, O_RDONLY);
		chop_help(d, i, j, fd);
	}
	return (0);
}

/*
===========================================================
						parsing map
						stockage data

===========================================================
*/
int	main_parsing(char *file, t_game *data)
{
	if (check_extension(file, ".cub"))
		return (1);
	if (ft_file_empty(file))
		return (1);
	if (ft_init_split(file, data, 0, 0) || ft_init_texture(data))
		return (1);
	if (check_exist(data, 0, 0))
		return (1);
	if (check_rgb_c(data) || check_rgb_f(data))
		return (1);
	data->map = data->split + data->index;
	if (chop_texture(data, -1, 0, 0) || check_xpm(data))
		return (1);
	if (parse_map(data))
		return (1);
	data->choice = 1;
	return (0);
}
