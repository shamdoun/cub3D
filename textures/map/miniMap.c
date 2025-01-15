/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:38:26 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/22 21:48:33 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	cast_to_window(double old_v, int o_l, int o_m, int flag)
{
	if (flag)
		return (((old_v - o_l) * (W_HEIGHT * BLOCK_L) / (o_m - o_l)));
	return (((old_v - o_l) * (W_WIDTH * BLOCK_W)) / (o_m - o_l));
}

void	draw_pixel(t_map_e *m, int i, int j, t_minimap *mini)
{
	if (m->m_values[(int)floor((int)mini->j2
				/ BLOCK_L)][(int)floor(mini->i2 / BLOCK_W)] == '1')
		mlx_put_pixel(m->interface->new_img, (i),
			(j), get_rgba(32, 30, 31, 150));
	else if (m->m_values[(int)floor(mini->j2
				/ BLOCK_L)][(int)floor(mini->i2 / BLOCK_W)] == '0')
		mlx_put_pixel(m->interface->new_img, (i),
			(j), get_rgba(255, 255, 255, 255));
	else if (m->m_values[(int)floor(mini->j2
				/ BLOCK_L)][(int)floor(mini->i2 / BLOCK_W)] == 'D')
	{
		mlx_put_pixel(m->interface->new_img, (i),
			(j), get_rgba(100, 0, 250, 100));
	}
	else
		mlx_put_pixel(m->interface->new_img, (i),
			(j), get_rgba(153, 70, 54, 50));
}

void	draw_map_2(t_minimap *mini, int i, int j, t_map_e *m)
{
	int	l;

	if (mini->i2 >= 0 && mini->j2 >= 0
		&& mini->j2 < (m->height * BLOCK_L) && mini->i2 < (m->width * BLOCK_W))
	{
		l = ft_strlen(m->m_values[(int)mini->j2 / BLOCK_L]) * BLOCK_L;
		if (mini->i2 < l)
		{
			draw_pixel(m, i, j, mini);
		}
		else
			mlx_put_pixel(m->interface->new_img,
				(i), (j), get_rgba(153, 70, 54, 50));
	}
	else
		mlx_put_pixel(m->interface->new_img, (i),
			(j), get_rgba(153, 70, 54, 50));
}

void	draw_map_1(t_map_e *m)
{
	int					j;
	int					i;
	static t_minimap	*mini;

	if (!mini)
	{
		mini = ft_malloc(sizeof(t_minimap), 0);
		if (!mini)
			exit(1);
	}
	mini->begin_i = m->player->x_p - M_M_W * BLOCK_W;
	mini->begin_j = m->player->y_p - M_M_H * BLOCK_L;
	j = -1;
	while (++j < (2 * M_M_W * 20))
	{
		i = -1;
		while (++i < (M_M_W * 2 * 20))
		{
			mini->j2 = mini->begin_j + (double)j * BLOCK_W / 20;
			mini->i2 = mini->begin_i + (double)i * BLOCK_L / 20;
			draw_map_2(mini, i, j, m);
		}
	}
}

void	draw_mini_map(t_map_e *m)
{
	draw_map_1(m);
	draw_player(m);
}
