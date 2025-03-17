/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:17 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/17 16:18:06 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int check_extension(char *file)
{
	char *extension;
	
	extension = ft_strrchr(file, '.');
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
	data->index = j;// rammene mon index a la deniere texture + 1
	if(count < 5 || CheckAlreadyExist(data))
		return (1);
	return (0);
}

/*
===================================================

			Check le bon format du sol et du plafond
===================================================
*/

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
	if (limit_number_rgb(data->split[i] + j))
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
	if (limit_number_rgb(data->split[i] + j))
		return (1);
	while (data->split[i][j])
	{
		if ((data->split[i][j] < '0' || data->split[i][j] > '9') && data->split[i][j] != ',')
			return (1);
		j++;
	}
	return (0);
}

/*
==================================================
	fonction va chercher et checker les chemins des textures
	et qui les stock dans la data            
==================================================
*/

int	chop_texture(t_game *data, int i, int j)
{
	while (data->split[i] && i < data->index)// tant qu'on a pas depasser toutes les textures
	{
		j = 0;
		while (data->split[i][j] && data->split[i][j] >= 'A' && data->split[i][j] <= 'Z')
			j++;
		while(data->split[i][j] && data->split[i][j] == ' ')
			j++;
		if (access((const char *)data->split[i] + j, F_OK) < 0 &&
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
		i++;
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
	if (check_extension(file))// verifie la bonne extension
		return (1);

	if (ft_file_empty(file))// verifie si le fichier est vide
		return (1);

	ft_init_texture(data);// initialise mon tableau de cle de texture
//----------------------------------------------------------------------
	ft_init_split(file, data);// recup toutes les lignes du tableau
	if (CheckExist(data, 0, 0)) // verifie si les cles de textures existe et check les doublons
		return (printf("checkexist"), 1);
	if (check_RGB_C(data) || check_RGB_F(data))
		return (1);
	
	data->map = data->split + data->index;
	if (chop_texture(data, 0, 0))// recupere les chemins des textures en verifiant l'access
		return (1);
	if (parse_map(data))
		return (1);
	
	return (0);
}
