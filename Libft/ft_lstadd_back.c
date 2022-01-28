/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:51 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:50:59 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Obtain the first element of the list and point
		to it with current.
	- Iterate over the list thanks to current.
	- When we find the "next" as NULL, is the last element
		so, we make it to point to the "new" element.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new;
		}
	}
}
