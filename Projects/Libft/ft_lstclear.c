/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:51:34 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:51:40 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Iterate over the list of elements
	- Apply the free function
	- Use aux to be able to go to the next element in "lst"
	- Put null the list.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*aux;

	current = *lst;
	while (current != NULL)
	{
		aux = current;
		ft_lstdelone(current, del);
		current = aux->next;
	}
	*lst = NULL;
}
