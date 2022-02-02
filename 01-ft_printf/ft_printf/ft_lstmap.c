/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:53:01 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:53:07 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Create the firts list as NULL
		- Iterate over "lst"
		- Apply the "f" function to the current content 
			of the current element fo the list. And <<proof>>
		- Create the new element (with that new conctent)
			to add to the list. And <<proof>>
		- Add the element to the list at the end.
	
	<<proof>> : if something goes wrong, clear all work done
		and return NULL. Using my function "clear_list" to not
		repeat code
*/

static void	*clear_list(t_list *list, void (*del)(void *))
{
	ft_lstclear(&list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_list;
	t_list	*element_list;

	current = lst;
	new_list = NULL;
	while (current != NULL)
	{
		element_list = ft_lstnew(f(current->content));
		if (element_list == NULL)
			return (clear_list(new_list, del));
		ft_lstadd_back(&new_list, element_list);
		current = current->next;
	}
	return (new_list);
}
