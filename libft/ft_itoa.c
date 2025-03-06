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

int	count_itoa(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	long int		n1;
	char			*new;
	int				i;

	i = 0;
	n1 = n;
	len = count_itoa(n);
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	if (n1 < 0)
	{
		new[0] = '-';
		n1 *= -1;
		i++;
	}
	new[len] = '\0';
	while (--len >= i)
	{
		new[len] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	return (new);
}
