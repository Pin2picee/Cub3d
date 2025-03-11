/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/11 17:44:19 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"


int check_extension(char *file)
{
	char *extension;
	
	extension = ft_strchr(file, '.');
	if (!extension || ft_strcmp(extension, ".cub"))// si pas de . ou extension differente
	{
		return (1);
	}
	return (0);
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
			if (!ft_strncmp(TextureName[i], line, ft_strlen(TextureName[i])))
			{
				j++;
			}
			free(line);
			line = get_next_line(fd);
		}
		if (j > 1)
			return (close(fd), 1);
	}
	free(line);
	return (close(fd), 0);
}

/*
=======================================================
				Check si toutes les clefs existe
				et appel la check doublon
=======================================================
*/
int	CheckExist(char *file, char **TextureName)
{
	int		fd;
	char	*line;
	int		i;
	
	i = 0;
	fd = open (file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && !ft_strnstr(line, "111", ft_strlen(line)))
	{
		i = 0;
		while (TextureName[i])
		{
			if (!ft_strncmp(line, TextureName[i], ft_strlen(TextureName[i])) || !ft_strcmp("\n", line))
				break;
			if (i == 5)
				return (1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	
	if(CheckAlreadyExist(file, TextureName))
		return (close(fd), 1);
	return (close(fd), 0);
}

/*
==================================================
	fonction va chercher les chemins des textures
	et qui les stock dans la data            
==================================================
*/
int check_texture(char *file, t_game *d, int fd)
{
	int     i;
	char    *line;
	
	// initialise mon tableau de de name texture
	i = 0;
	d->texture = (char **)ft_calloc(7, sizeof(char *));
   while (i < 6)
   {
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);
		while(line != NULL && !ft_strnstr(line, "111", ft_strlen(line)))
		{
			if (ft_strnstr(line, d->TextureName[i], ft_strlen(d->TextureName[i])))
			{
				d->texture[i] = ft_strdup(line);
				i++;
				get_next_line(-42);
				close(fd);
				free(line);
				break;
			}
			free(line);
			line = get_next_line(fd);
		}
		if (line == NULL)
			return (1);
   }
   return (close(fd), 0);
}

/*
==================================================
				fonction qui push 
				dans le tableau ma map
==================================================
*/

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

int	fd_to_map(int fd, int total_lu, t_game *game)
{
	char *line;
	char *tmp_str;
	char *new_ptr;
	
	while(42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (perror("Error\n"), 1);
		if (!strstr(line, "NO") && !strstr(line, "SO") && !strstr(line, "WE") && !strstr(line, "EA") && line[0] != 'C' && line[0] != 'F' && !ft_line_empty(line))
			break;
	}
	
	new_ptr = ft_strjoin(line, tmp_str);
	
	

}

/*
===========================================================
						parsing map
						stockage data

===========================================================
*/
int main_parsing(char *file, t_game *data)
{
	int fd;
	int i_map;//indice de la map
	
	
	if (check_extension(file))// verifie la bonne extension
		return (1);
	if (ft_file_empty(file))// verifie si le fichier est vide
		return (1);
	ft_init_texture(data);
	if (CheckExist(file, data->TextureName))
		return (printf("checkexist"), 1);
	//if (check_texture(file, data, 0))// verifie si toutes les textures sont bonne
		//return (1);
	/*
	fd = open(file, O_RDONLY);
	if (fd_to_map())
	*/
	return (0);
	close(fd);
}
