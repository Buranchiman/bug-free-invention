/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:09:39 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 15:45:00 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest <= src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

//int main()
//{
//    char src[] = "salut";
//    char dest[10];
//    printf("%s \n",(char *)ft_memmove(src + 1, src, 2));
//    printf("%s \n", (char *)ft_memmove(dest, src, 3));
//    printf("%s \n",(char *)memmove(src + 1, src, 2));
//    printf("%s", (char *)memmove(dest, src, 3)); 
//}
