/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:28:42 by ahmansou          #+#    #+#             */
/*   Updated: 2019/04/07 13:23:06 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char*)s;
	while (i < n)
	{
		if ((unsigned char)ss[i] == (unsigned char)c)
			return (ss + i);
		i++;
	}
	return (NULL);
}
