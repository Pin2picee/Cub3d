/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_PARSING.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:20:03 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/12 18:02:54 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"


int ft_line_empty(char *line)
{
	int i;

	i = 0;
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

void	ft_init_texture(t_game *d)
{
	int	i;

	i = 0;
	d->TextureName = (char **)ft_calloc(7, sizeof(char *));
	while (i < 6)
	{
		d->TextureName[i] = (char *)ft_calloc(3, sizeof(char *));
		i++;
	}
	d->TextureName[0] = "NO ";
	d->TextureName[1] = "SO ";
	d->TextureName[2] = "WE ";
	d->TextureName[3] = "EA ";
	d->TextureName[4] = "C ";
	d->TextureName[5] = "F ";
}



/*
==================================================
	verifie si le fichiers et vide           
==================================================
*/

int ft_file_empty(char *file)
{
	int		fd;
	int     nb_lu;
	int     total_lu;
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



/*
======================================================
				Check si doublon
======================================================
*/
int	CheckAlreadyExist(char *file, char **TextureName)
{
	int		fd;
	int		i;
	char	*line;
	int		j;
	
	i = 0;
	j = 0;
	while (TextureName[i])
	{
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);
		j = 0;
		while (line != NULL && !ft_strnstr(line, "111", ft_strlen(line)))
		{
			if (!ft_strncmp(TextureName[i], line, ft_strlen(TextureName[i])))// si je tombe dessus
				j++;// incremente le compteur de deja vue;
			free(line);
			line = get_next_line(fd);
		}
        if (line)
            free(line);
        close(fd);
        get_next_line(-42);
		if (j > 1)
				return (1);
        i++;
	}
	return (0);
}
