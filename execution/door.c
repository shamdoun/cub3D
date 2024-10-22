/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:14:17 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/23 00:20:23 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	mouvement_is_blocked_o(t_map_e *m, int map_y, int map_x, double angle)
{
	int	h;

	h = 0;
	while (m->m_values[h])
		h++;
	if ((m->m_values[map_y][map_x] == 'O') || (!ray_is_facing_down(angle)
			&& ray_is_facing_left(angle) && (m->m_values[map_y][map_x + 1] == 'O')
					&& (((map_y + 1) < h)
					&& (map_x < ((int)ft_strlen(m->m_values[map_y + 1]))))
					&& (m->m_values[map_y + 1][map_x] == 'O')) ||
		(!ray_is_facing_down(angle) && !ray_is_facing_left(angle)
				&& (m->m_values[map_y][map_x - 1] == 'O')
				&& ((map_y + 1) < h
				&& (map_x < (int)ft_strlen(m->m_values[map_y + 1])))
				&& (m->m_values[map_y + 1][map_x] == 'O')) ||
		(ray_is_facing_down(angle) && ray_is_facing_left(angle)
				&& (m->m_values[map_y][map_x + 1] == 'O')
				&& (m->m_values[map_y - 1][map_x] == 'O')))
            m->flag = 1;
}

int	mouvement_is_blocked_d(t_map_e *m, int map_y, int map_x, double angle)
{
	int	h;

	h = 0;
	while (m->m_values[h])
		h++;
	mouvement_is_blocked_o(m, map_y, map_x, angle);
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

void open_door(struct mlx_key_data key, void *param)
{
	t_map_e	*m;

	m = (t_map_e *)param;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
	{
		printf("flag = %d\n", m->flag);
		printf("open = %d\n", m->open);
		if (m->flag == 1 && m->open == 0 && m->dis < 60)
		{
			printf("im opening the door\n");
			m->m_values[(int)floor(m->my_y / BLOCK_L)][(int)floor(m->my_x / BLOCK_W)] = 'O';
			m->open = 1;
			return ;
		}
		else if (m->flag == 1 && m->open == 1 && m->dis < 60)
		{
			return ;
			printf("im closing the door\n");
			m->m_values[(int)floor(m->my_y / BLOCK_L)][(int)floor(m->my_x / BLOCK_W)] = 'D';
			m->open = 0;
		}
	}
}
