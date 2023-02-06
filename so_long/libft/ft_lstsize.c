/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:48:48 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/30 12:52:33 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		*lst = *lst->next;
		i++;
	}
	return (i);
}

/*int main ()
{
	t_list *first = ft_lstnew("bruh");
	t_list *second = ft_lstnew("mynamejeff");

	first->next = second;
	printf("%i", ft_lstsize(first));
}*/