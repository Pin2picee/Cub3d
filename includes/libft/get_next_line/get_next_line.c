/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbetcher <mbetcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:49:43 by abelmoha          #+#    #+#             */
/*   Updated: 2024/12/07 20:39:49 by mbetcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_liste	*stash = NULL;
	char			*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0
		|| read(fd, 0, 0) < 0)
		return (free(stash->content), free(stash), stash = NULL, NULL);
	ligne = NULL;
	read_and_stash(&stash, fd);
	if (stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	extract_line(stash, &ligne);
	clean_stash(&stash);
	if (ligne[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

// utilise read pour mallocer la taille de mon buffer et ajouter un '\0'
// puis appel une fonction qui va copier mon buffer dans le dernier
// maillon qu'on aura malloc
void	read_and_stash(t_liste **stash, int fd)
{
	char	*buff;
	int		lettre_lu;

	lettre_lu = 1;
	while (found_newline(*stash) != 1 && lettre_lu != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		lettre_lu = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && lettre_lu == 0) || lettre_lu == -1)
		{
			free(buff);
			return ;
		}
		buff[lettre_lu] = '\0';
		buff_to_stash(stash, buff, lettre_lu);
		free(buff);
	}
}

void	buff_to_stash(t_liste **stash, char *buff, int lettre_lu)
{
	int		i;
	t_liste	*last;
	t_liste	*new_node;

	new_node = malloc(sizeof(t_liste));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (lettre_lu + 1));
	if (new_node == NULL)
		return ;
	i = 0;
	while (buff[i] && i < lettre_lu)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = last_maillon(*stash);
	last->next = new_node;
}

void	extract_line(t_liste *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_liste **stash)
{
	t_liste	*last;
	t_liste	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_liste));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = last_maillon(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(1 * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
