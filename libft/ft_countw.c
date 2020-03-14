/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:03 by ahmansou          #+#    #+#             */
/*   Updated: 2019/04/12 15:34:10 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countw(char *hay, char *needle)
{
	int i;
	int j;
	int k;
	int wc;

	i = 0;
	wc = 0;
	while (hay[i])
	{
		j = 0;
		if (hay[i] == needle[j])
		{
			k = i;
			while (hay[k] == needle[j])
			{
				k++;
				j++;
				if (!needle[j])
					wc++;
			}
		}
		i++;
	}
	return (wc);
}
