/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_1st_line_lenght.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:13:35 by vdruta            #+#    #+#             */
/*   Updated: 2015/09/24 22:45:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_find_1st_line_lenght(char **str)
{
	int j;

	j = 0;
	while (str[0][j] != '\n')
	{
		j++;
	}
	return (j);
}
