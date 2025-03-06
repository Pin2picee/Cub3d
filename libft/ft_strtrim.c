/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/17 14:45:54 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_char(char c, char const *set)
{
	if (ft_strchr(set, c) == NULL)
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, 1));
	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_check_char(s1[start], set))
		start++;
	while (s1[end] && end > start && ft_check_char(s1[end], set))
		end--;
	str = malloc((end - start + 2) * sizeof (char));
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
