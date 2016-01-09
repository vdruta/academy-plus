/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:31:19 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 16:25:17 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	change_coordinates_node(t_tetris *list, unsigned char size)
{
	unsigned char	*new_coordinates;
	unsigned char	index;

	new_coordinates = (unsigned char*)malloc(sizeof(unsigned char) * 4);
	index = 0;
	while (index < 4)
	{
		new_coordinates[index] = list->coordinates[2 * index + 1] * (size + 1) +
			list->coordinates[2 * index];
		index++;
	}
	free(list->coordinates);
	list->coordinates = new_coordinates;
}

void	change_coordinates(t_tetris *list, unsigned char size)
{
	t_tetris	*node;
	
	node = list;
	while (node)
	{
		change_coordinates_node(node, size);
		node = node->next;
	}
}

static void	increment_coordinates_node(t_tetris *list, unsigned char size)
{
	unsigned char	*new_coordinates;
	unsigned int	index;

	new_coordinates = (unsigned char*)malloc(sizeof(unsigned char) * 4);
	index = 0;
	while (index < 4)
	{
		new_coordinates[index] = list->coordinates[index] +
			list->coordinates[index] / size;
		index++;
	}
	free(list->coordinates);
	list->coordinates = new_coordinates;
}

void	increment_coordinates(t_tetris *list, unsigned char size)
{
	t_tetris	*node;

	node = list;
	while (node)
	{
		increment_coordinates_node(node, size);
		node = node->next;
	}
}
