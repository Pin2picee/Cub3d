/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:30:30 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/10 23:37:59 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else if (n < 0)
	{
		write (fd, "-", 1);
		ft_putnbr_fd((n * (-1)), fd);
	}
	else
	{
		ft_putnbr_fd ((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}
