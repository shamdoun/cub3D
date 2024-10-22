/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:00:09 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/22 23:15:04 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_map_value(char **mapValues, t_player *p, int x, int y)
{
	char	v;

	v = mapValues[(int)floor((p->y_p + y)
			/ BLOCK_L)][(int)floor((p->x_p + x) / BLOCK_L)];
	if (v == '1' || v == 'D')
		return (1);
	return (0);
}

int	wall_contact(t_player *p, char **mapValues)
{
	if (get_map_value(mapValues, p, 0, -10)
		|| get_map_value(mapValues, p, 10, 0)
		|| get_map_value(mapValues, p, -10, 0)
		|| get_map_value(mapValues, p, 0, 10)
		|| get_map_value(mapValues, p, -10, 10)
		|| get_map_value(mapValues, p, -10, -10)
		|| get_map_value(mapValues, p, 10, -10)
		|| get_map_value(mapValues, p, 10, 10))
		return (1);
	return (0);
}

int	row_empty(char *s)
{
	int	i;
	int	empty;

	i = 0;
	empty = 1;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != 9)
			empty = 0;
		i++;
	}
	return (empty);
}
