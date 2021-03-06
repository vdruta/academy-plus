/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:53:02 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:27:35 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env *m;

	m = (t_env*)malloc(sizeof(*m));
	ft_init_env(m, argc, argv);
	ft_transform_all_points_relative_to_map_center(m);
	mlx_expose_hook(m->win, expose_hook, m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
