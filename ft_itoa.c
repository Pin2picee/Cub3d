/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:12:17 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/11 00:15:51 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_len(int nb)
{
	size_t	compteur;

	compteur = 0;
	if (nb == 0)
		return (compteur + 1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		compteur += 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		compteur++;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nombre;
	int		s_negative;
	int		index;

	nombre = (long)n;
	index = ft_check_len(n) - 1;
	s_negative = 0;
	str = malloc(ft_check_len(n) * sizeof(unsigned char) + 1);
	if (!str)
		return (NULL);
	if (nombre < 0)
	{
		nombre = -nombre ;
		str[0] = '-';
		s_negative += 1;
	}
	while (index >= s_negative)
	{
		str[index] = nombre % 10 + '0';
		nombre /= 10;
		index--;
	}
	str[ft_check_len(n)] = '\0';
	return (str);
}
