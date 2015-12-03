/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:02:56 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 15:29:29 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_(va_list ap, int *bytes, char *descriptor)
{
	int			nbr;
	intmax_t	nbr2;
	char	 	*str;

	if (ft_strchr(descriptor, 'l'))
		ft_process_dd_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'j'))
	{
		nbr2 = va_arg(ap, intmax_t);
		str = ft_intmax_t_to_ascii_base(nbr2, 10);
	}
	else
	{
		nbr = va_arg(ap, int);
		str = ft_intmax_t_to_ascii_base(nbr, 10);
	}
/* print side of the file*/	
	if (ft_strchr(descriptor, '+') && nbr >= 0 && !ft_strchr(descriptor, 'l'))
	{
		ft_putchar('+');
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else if (ft_strchr(descriptor, ' ') && nbr >= 0 && !ft_strchr(descriptor, 'l'))
	{
		ft_putchar(' ');
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else if (!ft_strchr(descriptor, 'l'))
	{
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}
}
