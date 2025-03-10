/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.C                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/10 17:08:21 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/LIB.H"


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
==================================================
    fonction va chercher les chemins des textures
    et qui les stock dans la data            
==================================================
*/

/**
 * verifications des doublons
 * qu'il n'en manque pas un
 * 
*/
int check_texture(char *file, t_game *d, int fd)
{
    char *line;
    
    fd = open(file, O_RDONLY);
    while (42)
    {
        line = get_next_line(fd);
        if (line == NULL || ft_strnstr(line, "111", ft_strlen(line)))
            return (close(fd), get_next_line(-42), 1);
        if (line[0] == 'C')
        {
            if (d->C != NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
            d->C = ft_strdup(ft_strnstr(line, "0123456789", ft_strlen(line)));
        }  
        else if (line[0] == 'F')
        {
            if (d->F == NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
             d->F = ft_strdup(ft_strnstr(line, "0123456789", ft_strlen(line)));
        }
        else if (ft_strnstr(line, "NO", 2))
        {
            if (d->NO != NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
            d->NO = ft_strdup(ft_strchr(line, '/'));
        }
        else if (ft_strnstr(line, "SO", 2))
        {
            if (d->SO != NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
            d->SO = ft_strdup(ft_strchr(line, '/'));
        }
        else if (ft_strnstr(line, "WE", 2))
        {
            if (d->WE != NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
            d->WE = ft_strdup(ft_strchr(line, '/'));
        }
        else if (ft_strnstr(line, "EA", 2))
        {
            if (d->EA != NULL)
                return (perror("Error\n"), free(line), close(fd), 1);
            d->EA = ft_strdup(ft_strchr(line, '/'));
        }
        free(line);
        if (d->NO && d->SO && d->EA && d->C && d->F && d->WE)
            break;
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
    if (check_texture(file, data, 0))// verifie si toutes les textures sont bonne
        return (1);
    fd = open(file, O_RDONLY);
    if (fd_to_map())
    close(fd);
}
