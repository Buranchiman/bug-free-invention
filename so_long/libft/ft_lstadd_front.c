/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:26:31 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/30 12:50:50 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{	
		new->next = *lst;
		*lst = new;
	}
}

/*int main ()
{
	t_list *new = ft_lstnew("hello there!");
	t_list *lst;

	lst = ft_lstnew("hey");
	ft_lstadd_front(&lst, new);
	printf("%s", (char *)(lst->content)); 
}*/
