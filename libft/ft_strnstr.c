/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:49:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/21 17:27:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = 0;
	while (s2[len])
		len++;
	if (len == 0)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		while (s2[j] == s1[i + j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char*)(s1 + i));
		j = 0;
		i++;
	}
	return (NULL);
}
