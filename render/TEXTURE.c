/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEXTURE.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:00:35 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 16:02:34 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

/*
=============================================
		Donne l'indice x a 
		afficher de la texture
=============================================
*/
int	ft_do_x(t_game *d)
{
	int	tmp;

	if (d->choice == 0 || d->choice == 1)
		tmp = (int)(d->r_y * d->tab_img[d->choice]->width)
			% d->tab_img[d->choice]->width;
	else
		tmp = (int)(d->r_x * d->tab_img[d->choice]->width)
			% d->tab_img[d->choice]->width;
	return (tmp);
}
