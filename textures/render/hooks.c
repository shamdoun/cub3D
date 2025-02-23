/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:13:10 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/21 19:58:59 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	rotate_angle(t_player *p, int value)
{
	p->angle += value;
	if (p->angle >= 360)
		p->angle -= 360;
	else if (p->angle < 0)
		p->angle += 360;
}

void	terminate_game(t_map_e *m)
{
	mlx_delete_image(m->interface->mlx_ptr, m->interface->new_img);
	mlx_close_window(m->interface->mlx_ptr);
	mlx_terminate(m->interface->mlx_ptr);
	free(m->interface);
	free(m->player);
	exit(1);
}

static void	update_map(t_map_e *m)
{
	mlx_delete_image(m->interface->mlx_ptr, m->interface->new_img);
	m->interface->new_img = mlx_new_image(m->interface->mlx_ptr,
			W_WIDTH * BLOCK_W, W_HEIGHT * BLOCK_L);
	if (!m->interface->new_img)
		terminate_game(m);
	draw_3d_walls(m);
	draw_mini_map(m);
	mlx_image_to_window(m->interface->mlx_ptr, m->interface->new_img, 0, 0);
}

void	key_func(void *param)
{
	t_map_e	*m;

	m = (t_map_e *)param;
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_RIGHT))
		rotate_angle(m->player, -13);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_LEFT))
		rotate_angle(m->player, 13);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_D))
		move_right(m->player, m->m_values);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_A))
		move_left(m->player, m->m_values);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_W))
		move_up(m->player, m->m_values);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_S))
		move_down(m->player, m->m_values);
	if (mlx_is_key_down(m->interface->mlx_ptr, MLX_KEY_ESCAPE))
		terminate_game(m);
	update_map(m);
}
