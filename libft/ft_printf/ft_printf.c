/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:14:40 by abelmoha          #+#    #+#             */
/*   Updated: 2024/04/19 17:39:31 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_next_pourcent(const char s, va_list args, int *len)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), len);
	if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	if (s == 'p')
		ft_putpointer(va_arg(args, void *), len);
	if (s == 'x' || s == 'X')
		ft_puthexa(va_arg(args, unsigned int), s, len);
	if (s == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), len);
	if (s == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	int				len;
	va_list			args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_next_pourcent(s[i], args, &len);
			i++;
		}
		else
		{
			ft_putchar(s[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

//int	main(void){//
//	ft_printf(" NULL %s NULL ", NULL);
	//printf("%%");  Doit afficher "c"ft_printf("%%");  Doit afficher "c"
//     int a = ft_printf("c'est %s ou bien %X\n", "salut", 1205);
//int b = printf("c'est %s ou bien %X\n", "salut", 1205); 
// Doit afficher "Salut"
// 	printf("Valeur Retour = %d\n", a);
// 	printf("Valeur Retour = %d\n", b);
//	ft_printf("%d", -1); // Doit afficher une adresse en hexa 0x
//    // ft_printf("%d\n", -75); // Doit afficher "-75"
//     //ft_printf("%u\n", -1); // Doit afficher "4294967295"
//     //ft_printf("%x\n", 1257); // Doit afficher "4E9"
//     //ft_printf("%%\n"); // Doit afficher "%"
//    // ft_printf("%c%s%p%d%u%x%%", 'c', "Salut", "adresse", -75, -1, 1257);
//     // Doit pouvoir afficher toutes les instances precedentes a la suite
//	return (0);
//}
