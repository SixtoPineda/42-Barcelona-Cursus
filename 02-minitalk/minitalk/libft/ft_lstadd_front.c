/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:51:12 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:51:19 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	+ Case: if "lst" is NULL, make to point "lst" to new
		as first list

	+ Case: "lst" and "new" have any list (no NULL)
		- Make the "next" list of "new" to be
			the first list that is pointing "lst".
		- "lst" now point to the list "new" a first list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL && new != NULL)
		*lst = new;
	else if (new != NULL && lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}	
}
