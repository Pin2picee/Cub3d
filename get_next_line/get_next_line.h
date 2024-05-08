/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:50:00 by abelmoha          #+#    #+#             */
/*   Updated: 2023/12/04 00:36:54 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h> // enlever

//     Mon buffer temp
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// ma structure que je vais chainer pour chaque liste

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

// utils

void	extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
t_list	*last_maillon(t_list *stash);
int		found_newline(t_list *stash);
int		ft_strlen(const char *str);
void	free_stash(t_list *stash);

// principal
char	*get_next_line(int fd);
void	buff_to_stash(t_list **stash, char *buff, int lettre_lu);
void	read_and_stash(t_list **stash, int fd);

void	clean_stash(t_list **stash);

#endif