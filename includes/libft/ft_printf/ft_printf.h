/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:51:32 by abelmoha          #+#    #+#             */
/*   Updated: 2023/11/30 22:42:00 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

// alpha :
void	ft_putstr(char *str, int *len);
void	ft_putchar(int c, int *len);

//number :
void	ft_putnbr(int nb, int *len);
void	ft_putunbr(unsigned int nb, int *len);
void	ft_puthexa(unsigned int nb, char format, int *len);
void	ft_putpointer(void *p, int *len);
void	ft_puthexa_pointer(unsigned long long nb, int *len);

//utils :
int		ft_printf(const char *s, ...);
void	ft_next_pourcent(const char s, va_list args, int *len);

#endif