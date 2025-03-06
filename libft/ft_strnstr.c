/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:14:24 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/11 00:36:50 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i_little;

	i = 0;
	i_little = 0;
	if (little[i_little] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		while (big[i + i_little] && big[i + i_little] == little[i_little] && \
			i + i_little < len)
			i_little++;
		if (little[i_little] == '\0')
			return ((char *)&big[i]);
		i++;
		i_little = 0;
	}
	return (0);
}
