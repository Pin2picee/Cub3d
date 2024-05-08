/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:36:48 by abelmoha          #+#    #+#             */
/*   Updated: 2023/10/17 14:41:22 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*premiere;

	if (!lst || !f || !del)
		return (NULL);
	premiere = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			new = premiere->next;
			(*del)(premiere->content);
			free(premiere);
			premiere = new;
			free(lst);
		}
		ft_lstadd_back(&premiere, new);
		lst = lst->next;
	}
	return (premiere);
}
