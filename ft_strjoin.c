/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:52:26 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/10 21:10:25 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	taille;
	size_t	i;
	size_t	i_new;
	char	*new_str;

	taille = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(taille * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	i_new = 0;
	while (s1[i_new])
	{
		new_str[i_new] = s1[i_new];
		i_new++;
	}
	i = 0;
	while (s2[i])
	{
		new_str[i_new] = s2[i];
		i++;
		i_new++;
	}
	new_str[i_new] = '\0';
	return (new_str);
}
