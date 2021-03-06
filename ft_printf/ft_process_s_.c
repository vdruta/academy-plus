/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:43:39 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/14 18:20:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s_width(char **str, t_arg arg)
{
	char *strp;

	if (arg.width > ft_strlen(*str))
	{
		strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(*str));
		*str = ft_strjoin(strp, *str);
	}
}

void	ft_process_s_flag_zero(char **str, t_arg arg)
{
	char *strp;

	if (arg.width > ft_strlen(*str))
	{
		strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		strp = ft_memset(strp, '0', arg.width - ft_strlen(*str));
		*str = ft_strjoin(strp, *str);
	}
}

void	ft_process_s_null_str_precision(int *bytes, char *descriptor, t_arg arg)
{
	char *str;

	str = ft_strdup("(null)");
	ft_process_s_precision(&str, arg);
	if (arg.precision == 0 && ft_strchr(descriptor, '.'))
		str = ft_strdup("");
	if (arg.width)
	{
		if (arg.flag_zero)
			ft_process_s_flag_zero(&str, arg);
		ft_process_s_width(&str, arg);
	}
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_s_val_str(char *str, int *bytes, char *descriptor, t_arg arg)
{
	if (arg.precision)
		ft_process_s_precision(&str, arg);
	if (arg.precision == 0 && ft_strchr(descriptor, '.'))
		str = ft_strdup("");
	if (arg.width)
	{
		if (arg.flag_zero)
			ft_process_s_flag_zero(&str, arg);
		ft_process_s_width(&str, arg);
	}
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_s_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	char *str;

	if (arg.lm_l)
		ft_process_ss_(ap, bytes, descriptor, arg);
	else
	{
		str = va_arg(ap, char *);
		if (str)
			ft_process_s_val_str(str, bytes, descriptor, arg);
		else if (!str && ft_strchr(descriptor, '.'))
			ft_process_s_null_str_precision(bytes, descriptor, arg);
		else
		{
			ft_putstr("(null)");
			*bytes += 6;
		}
	}
}
