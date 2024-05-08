/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:29:59 by abelmoha          #+#    #+#             */
/*   Updated: 2023/12/04 00:37:47 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = last_maillon(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*last_maillon(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

// generate_line compte les caracteres stocke dans
// chaque maillon puis les additione pour malloc la ligne a envoyez
// genere et malloc la ligne en parcourant chaque
// copy de mon buff sur chaque maillon
void	generate_line(char **line, t_list *stash)
{
	int	i_maillon;
	int	len;

	len = 0;
	while (stash)
	{
		i_maillon = 0;
		while (stash->content[i_maillon])
		{
			if (stash->content[i_maillon] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i_maillon++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
