/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:40:18 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/11 23:36:06 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_word(char const *str, char sep)
{
	size_t	i;
	size_t	compt;

	compt = 0;
	i = 0;
	if (ft_strlen(str) <= 1 && str[i] == sep)
		return (0);
	if (str[0] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		if (str[i] == sep)
		{
			compt += 1;
			i++;
		}
	}
	if (str[i] == '\0' && str[i - 1] != sep)
		compt++;
	return (compt);
}

size_t	ft_strlen_sep(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	len_mot;

	i = 0;
	j = 0;
	split = ft_calloc(ft_len_word(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len_mot = ft_strlen_sep((char *)s + i, c);
		split[j] = malloc((len_mot + 1) * sizeof(char));
		ft_memmove(split[j], (char *)s + i, len_mot);
		split[j][len_mot] = '\0';
		i += len_mot;
		j++;
	}
	return (split);
}
/*
int	main(void)
{
	char **split;
	int	i;
	
	i = 0;
	split = ft_split("  ", ' ');
	while(split[i])
	{
		printf("'%s' ", split[i]);
		i++;
	}
	return (0);
}
*/