/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:06:16 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 18:04:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_execute_116_121(t_env *m, int n)
{
	ft_control_height(m, n);
	expose_hook(m);
}

int		key_hook(int keycode, t_env *m)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 116)
		ft_execute_116_121(m, 1);
	if (keycode == 121)
		ft_execute_116_121(m, -1);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		ft_move(m, keycode);
		expose_hook(m);
	}
	if (keycode == 115 || keycode == 119)
	{
		ft_zoom(m, keycode);
		expose_hook(m);
	}
	if (keycode == 15 || keycode == 5 || keycode == 11)
	{
		ft_change_color(m, keycode);
		expose_hook(m);
	}
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
