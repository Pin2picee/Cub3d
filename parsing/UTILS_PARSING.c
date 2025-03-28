/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_PARSING.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:20:03 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:14:42 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int	ft_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '\n' || line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

/*
======================================================
				Init mes textures possibles
======================================================
*/
int	ft_init_texture(t_game *d)
{
	d->texture_name = (char **)ft_calloc(7, sizeof(char *));
	if (!d->texture_name)
		return (1);
	d->texture_name[0] = ft_strdup("NO ");
	d->texture_name[1] = ft_strdup("SO ");
	d->texture_name[2] = ft_strdup("WE ");
	d->texture_name[3] = ft_strdup("EA ");
	d->texture_name[4] = ft_strdup("C ");
	d->texture_name[5] = ft_strdup("F ");
	d->texture_name[6] = NULL;
	return (0);
}

/*
==================================================
	verifie si le fichiers et vide           
==================================================
*/
int	ft_file_empty(char *file)
{
	int		fd;
	int		nb_lu;
	int		total_lu;
	char	buff_temp[1024];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	total_lu = 0;
	nb_lu = read(fd, buff_temp, sizeof(buff_temp));
	while (nb_lu > 0)
	{
		total_lu += nb_lu;
		nb_lu = read(fd, buff_temp, sizeof(buff_temp));
	}
	close(fd);
	if (total_lu < 1)
		return (1);
	return (0);
}

int	ft_init_split(char *file, t_game *data, int fd, int lettre_lu)
{
	int		total;
	char	buffer[4096];
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	lettre_lu = read(fd, buffer, BUFFERSIZ);
	if (!lettre_lu)
		return (1);
	total = lettre_lu;
	while (lettre_lu > 0)
	{
		lettre_lu = 0;
		lettre_lu = read(fd, buffer, BUFFERSIZ);
		total += lettre_lu;
	}
	close(fd);
	str = ft_calloc(sizeof(char), total + 1);
	if (!str)
		return (close(fd), 1);
	fd = open(file, O_RDONLY);
	lettre_lu = read(fd, str, total);
	data->split = ft_split(str, '\n');
	return (close(fd), free(str), 0);
}

/*
======================================================
				Check si doublon
				if (str[i] == ',')
======================================================
*/

int	check_already_exist(t_game *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 6 && data->texture_name[i])
	{
		j = 0;
		count = 0;
		while (data->split[j])
		{
			if (!ft_strncmp(data->split[j], data->texture_name[i],
					ft_strlen(data->texture_name[i])))
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
