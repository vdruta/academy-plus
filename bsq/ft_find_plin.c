/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_plin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:05:05 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 15:18:04 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	ft_find_plin(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	else
		while (str[i] != '\n')
			i++;
	return (str[i - 1]);
}
