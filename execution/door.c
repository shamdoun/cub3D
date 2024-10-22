/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:14:17 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/22 22:38:53 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouvement_is_blocked_d(t_map_e *m, int map_y, int map_x, double angle)
{
	int	h;

	h = 0;
	while (m->m_values[h])
		h++;
	if ((m->m_values[map_y][map_x] == 'D') || (!ray_is_facing_down(angle)
			&& ray_is_facing_left(angle) && (m->m_values[map_y][map_x + 1] == 'D')
					&& (((map_y + 1) < h)
					&& (map_x < ((int)ft_strlen(m->m_values[map_y + 1]))))
					&& (m->m_values[map_y + 1][map_x] == 'D')) ||
		(!ray_is_facing_down(angle) && !ray_is_facing_left(angle)
				&& (m->m_values[map_y][map_x - 1] == 'D')
				&& ((map_y + 1) < h
				&& (map_x < (int)ft_strlen(m->m_values[map_y + 1])))
				&& (m->m_values[map_y + 1][map_x] == 'D')) ||
		(ray_is_facing_down(angle) && ray_is_facing_left(angle)
				&& (m->m_values[map_y][map_x + 1] == 'D')
				&& (m->m_values[map_y - 1][map_x] == 'D')))
		{
            m->flag = 1;
            return (1);
        }
	return (0);
}
