/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:42:38 by ahmansou          #+#    #+#             */
/*   Updated: 2019/04/11 13:10:01 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*nxt;

	current = *alst;
	while (current)
	{
		nxt = current->next;
		del(current->content, current->content_size);
		free(current);
		current = nxt;
	}
	*alst = NULL;
}
