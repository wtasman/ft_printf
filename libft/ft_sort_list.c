/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:43:28 by wasman            #+#    #+#             */
/*   Updated: 2016/11/14 21:38:16 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_sort_list(t_list* lst, int (*cmp)(void *, void *))
{
		t_list	*lst1;
		t_list	*lst2;
		void*	tmp;

		lst1= lst;
		tmp = 0;
		while (lst1)
		{
			lst2 = lst1->next;
			while (lst2)
			{
				if (cmp(lst1->content, lst2->content) == 0)
				{
					tmp = lst1->content;
					lst1->content = lst2->content;
					lst2->content = tmp;
				}
				lst2 = lst2->next;
			}
			lst1 = lst1->next;
		}
		return (lst);
}
