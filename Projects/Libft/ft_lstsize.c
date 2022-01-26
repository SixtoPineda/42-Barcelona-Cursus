/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:53:36 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/25 13:53:43 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Create a aux struct "t_list" to iterate 
	over the list "lst".
*/

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*current;

	current = lst;
	cont = 0;
	while (current != NULL && lst != NULL)
	{
		cont++;
		current = current->next;
	}
	return (cont);
}
