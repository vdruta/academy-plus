/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_vid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:00:00 by vdruta            #+#    #+#             */
/*   Updated: 2015/09/24 22:33:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	ft_find_vid(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	else
		while (str[i] != '\n')
		{
			i++;
		}
		return (str[i - 3]);
}
