/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:35 by aclaros-          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:59 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*sol;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	sol = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&sol, del);
			return (NULL);
		}
		ft_lstadd_back(&sol, tmp);
		lst = lst->next;
	}
	return (sol);
}
