/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/27 18:11:51 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int check_extension(char *file, const char *extension)
{
	char *after_last_point;
	
	after_last_point = ft_strrchr(file, '.');
	if (!after_last_point || !extension || ft_strcmp(after_last_point, extension))
	{
		return (1);
	}
	return (0);
}

int	CheckExist(t_game *data, int i, int j)
{
	int		count;
	
	count = 0;
	while (data->split[j] && count < 6)
	{
		i = 0;
		while (data->TextureName[i])
		{
			if (!ft_strncmp(data->split[j], data->TextureName[i], ft_strlen(data->TextureName[i])))
			{
				count++;
				break ;
			}
			if (i == 5)
				return (1);
			i++;
		}
		j++;
	}
	while (ft_line_empty(data->split[j]))
		j++;
	data->index = j;
	if(count < 5 || CheckAlreadyExist(data))
		return (1);
	return (0);
}

int	check_RGB_F(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->split[i] && ft_strncmp(data->split[i], data->TextureName[5], 2))
		i++;
	while (data->split[i][j] && data->split[i][j] >= 'A' && data->split[i][j] <= 'Z')
		j++;
	while(data->split[i][j] && data->split[i][j] == ' ')
		j++;
	data->floor = ft_get_color_key(data->split[i] + j);
	if (limit_number_rgb(data->split[i] + j))
		return (1);
	if (no_number(data->split[i] + j))
		return (1);
	while (data->split[i][j])
	{
		if ((data->split[i][j] < '0' || data->split[i][j] > '9') && data->split[i][j] != ',')
			return (1);
		j++;
	}
	return (0);
}

int	check_RGB_C(t_game *data)
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	while (data->split[i] && ft_strncmp(data->split[i], data->TextureName[4], 2))
		i++;
	while (data->split[i][j] && data->split[i][j] >= 'A' && data->split[i][j] <= 'Z')
		j++;
	while(data->split[i][j] && data->split[i][j] == ' ')
		j++;
	data->ceiling = ft_get_color_key(data->split[i] + j);
	if (limit_number_rgb(data->split[i] + j))
		return (1);
	if (no_number(data->split[i] + j))
		return (1);
	while (data->split[i][j])
	{
		if ((data->split[i][j] < '0' || data->split[i][j] > '9') && data->split[i][j] != ',')
			return (1);
		j++;
	}
	return (0);
}


int	chop_texture(t_game *data, int i, int j, int fd)
{
	char	buffer[1];
	
	while (data->split[++i] && i < data->index)// tant qu'on a pas depasser toutes les textures
	{
		j = 0;
		while (data->split[i][j] && data->split[i][j] >= 'A' && data->split[i][j] <= 'Z')
			j++;
		while(data->split[i][j] && data->split[i][j] == ' ')
			j++;
		fd = open(data->split[i] + j, O_RDONLY);
		if ((fd < 0 || 0 > read(fd, buffer, sizeof(buffer))) &&
			(ft_strncmp(data->split[i], data->TextureName[4], 2) && ft_strncmp(data->split[i], data->TextureName[5], 2)))
			return (1);
		if (!ft_strncmp(data->split[i], data->TextureName[0], ft_strlen(data->TextureName[0])))
			data->NO = data->split[i] + j;
		else if (!ft_strncmp(data->split[i], data->TextureName[1], ft_strlen(data->TextureName[1])))
			data->SO = data->split[i] + j;
		else if (!ft_strncmp(data->split[i], data->TextureName[2], ft_strlen(data->TextureName[2])))
			data->WE = data->split[i] + j;
		else if (!ft_strncmp(data->split[i], data->TextureName[3], ft_strlen(data->TextureName[3])))
			data->EA = data->split[i] + j;
		else if (!ft_strncmp(data->split[i], data->TextureName[4], ft_strlen(data->TextureName[4])))
			data->C = data->split[i] + j;
		else if (!ft_strncmp(data->split[i], data->TextureName[5], ft_strlen(data->TextureName[5])))
			data->F = data->split[i] + j;
	}
	return (0);
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
	ft_init_data(data);
	if (check_extension(file, ".cub"))// verifie la bonne extension
		return (1);

	if (ft_file_empty(file))// verifie si le fichier est vide
		return (1);

	;// initialise mon tableau de cle de texture
//----------------------------------------------------------------------
	if (ft_init_split(file, data, 0, 0) || ft_init_texture(data))// recup toutes les lignes du tableau
		return (1);
	if (CheckExist(data, 0, 0)) // verifie si les cles de textures existe et check les doublons
		return (printf("checkexist"), 1);
	if (check_RGB_C(data) || check_RGB_F(data))
		return (1);
	
	data->map = data->split + data->index;
	if (chop_texture(data, -1, 0, 0) || check_xpm(data))// recupere les chemins des textures en verifiant l'access
		return (1);
	if (parse_map(data))
		return (1);
	data->choice = 1;
	// free si jamais faux
	return (0);
}

//TODO: check .xpm de chaque textures// FAIT
//TODO: check lorsque la map n'est plus la // FAIT
//TODO lorsque le personnage est dans un autre endroit que la map elle meme