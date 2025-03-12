/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/12 18:07:42 by abelmoha         ###   ########.fr       */
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
void chop_texture(char *file, t_game *d, int fd, int i)
{
	char    *line;

	d->texture = (char **)ft_calloc(7, sizeof(char *));
   while (i < 6 && d->texture != NULL)
   {
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);
		while(line != NULL && !ft_strnstr(line, "111", ft_strlen(line)))
		{
			if (ft_strnstr(line, d->TextureName[i], ft_strlen(d->TextureName[i])))
			{
				d->texture[i++] = ft_strdup(line);
				get_next_line(-42);
				free(line);
				break;
			}
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		if (line == NULL)
			return ;
   }
   return ;
}

/*
==================================================
				fonction qui push 
				dans le tableau ma map
==================================================
*/


/*
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
		if //(== a un 111 ou  "   " ou peut import qui fait partie de la map)
			break;
	}
	
	new_ptr = ft_strjoin(line, tmp_str);
	
	

}
*/

/*
===========================================================
						parsing map
						stockage data

===========================================================
*/
int main_parsing(char *file, t_game *data)
{
	int fd;
	//int i_map;//indice de la map
	
	
	if (check_extension(file))// verifie la bonne extension
		return (1);

	if (ft_file_empty(file))// verifie si le fichier est vide
		return (1);
		
	ft_init_texture(data);// initialise mon tableau de cle de texture
	
	if (CheckExist(file, data->TextureName)) // verifie si les cles de textures existe et check les doublons
		return (printf("checkexist"), 1);

	//chop_texture(file, data, fd, 0);// recupere les chemins des textures avec leurs cles
	
	
	/*
	fd = open(file, O_RDONLY);
	if (fd_to_map())
	*/
	return (0);
	close(fd);
}
