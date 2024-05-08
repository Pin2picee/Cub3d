/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:38:28 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/06 20:54:18 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	taille_dst;

	taille_dst = ft_strlen(dst);
	i = 0;
	if (taille_dst >= size)
		return (ft_strlen(src) + size);
	while (src[i] && taille_dst < size - 1)
	{
		dst[taille_dst] = src[i];
		i++;
		taille_dst++;
	}
	dst[taille_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(src + i));
}
