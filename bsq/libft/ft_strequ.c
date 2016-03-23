/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:18:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/24 19:35:22 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}