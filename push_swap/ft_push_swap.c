/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:41 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/13 13:49:00 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *l_a, int aitems)
{
	int	temp;

	if (aitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
}

void	ft_recreate_origin(int *l_b, int *bitems)
{
	int i;

	i = 0;
	while (i < *bitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(*bitems)--;
}

void	ft_push(int *l_a, int *aitems, int *l_b, int *bitems)
{
	int	temp;
	int	temp2;
	int	i;

	if (!*bitems)
		return ;
	if (*aitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < *aitems + 1)
		{
			if (i < *aitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_origin(l_b, bitems);
	(*aitems)++;
}

void	ft_rotate_first_to_end(int *l_a, int aitems)
{
	int temp;
	int i;

	if (aitems < 2)
		return ;
	i = 0;
	temp = l_a[0];
	while (i < aitems - 1)
	{
		l_a[i] = l_a[i + 1];
		i++;
	}
	l_a[aitems - 1] = temp;
}

void	ft_rotate_last_to_start(int *l_a, int aitems)
{
	int temp;
	int	i;

	if (aitems < 2)
		return ;
	temp = l_a[aitems - 1];
	i = aitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
}

int		ft_l_a_is_complete_and_sorted(int *l_a, int aitems, int items)
{
	int i;

	i = 0;
	if (aitems != items)
		return (0);
	while (i < aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_push_swap(int *l_a, int items, int *l_b)
{
	int			aitems;
	int			bitems;
	int			*l_sorted;
	t_pslist	*list;

	l_sorted = ft_bubble_sort(l_a, items);
//	ft_print_result(l_sorted, items);
//	ft_putchar('\n');
	list = NULL;
	ft_add_to_list(&list, l_sorted, l_a, items);
	aitems = items;
	bitems = 0;

	while (!ft_l_a_is_complete_and_sorted(l_a, aitems, items))
	{
		ft_find_shortest_route_of_smallest_number();
	}

	ft_swap(l_a, aitems); //sa
	ft_push(l_b, &bitems, l_a, &aitems); //pb
	ft_rotate_first_to_end(l_a, aitems); //ra
	ft_rotate_last_to_start(l_a, aitems); //rra

	ft_print_result(l_a, aitems);
	ft_putchar('\n');
//	ft_print_result(l_b, bitems);
}