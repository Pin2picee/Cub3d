/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:49:45 by abelmoha          #+#    #+#             */
/*   Updated: 2023/11/30 22:43:29 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-nb, len);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + '0', len);
}

void	ft_putunbr(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10, len);
		ft_putunbr(nb % 10, len);
	}
	else
		ft_putchar(nb + '0', len);
}

void	ft_puthexa(unsigned int nb, char format, int *len)
{
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, format, len);
		ft_puthexa(nb % 16, format, len);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0', len);
	else if (format == 'x')
		ft_putchar((nb - 10) + 'a', len);
	else if (format == 'X')
		ft_putchar((nb - 10) + 'A', len);
}

void	ft_puthexa_pointer(unsigned long long nb, int *len)
{
	if (nb >= 16)
	{
		ft_puthexa_pointer(nb / 16, len);
		ft_puthexa_pointer(nb % 16, len);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0', len);
	else
		ft_putchar((nb - 10) + 'a', len);
}

void	ft_putpointer(void *p, int *len)
{
	if (p == NULL)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_puthexa_pointer((unsigned long long)p, len);
}
