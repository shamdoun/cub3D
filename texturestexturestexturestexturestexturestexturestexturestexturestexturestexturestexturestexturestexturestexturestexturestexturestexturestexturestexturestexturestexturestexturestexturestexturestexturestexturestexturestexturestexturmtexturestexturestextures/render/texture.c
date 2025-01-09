/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:13:55 by shamdoun          #+#    #+#             */
/*   Updated: 2025/01/08 21:42:59 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_textures_2(t_map_e *m, t_map *data)
{
	m->all_textures[2] = mlx_load_png(data->no);
	if (!m->all_textures[2])
	{
		mlx_delete_texture(m->all_textures[0]);
		mlx_delete_texture(m->all_textures[1]);
		free_all_exit(m, data);
	}
	m->all_textures[3] = mlx_load_png(data->so);
	if (!m->all_textures[3])
	{
		mlx_delete_texture(m->all_textures[0]);
		mlx_delete_texture(m->all_textures[1]);
		mlx_delete_texture(m->all_textures[2]);
		free_all_exit(m, data);
	}
}

void	init_textures(t_map_e *m, t_map *data)
{
	m->all_textures = ft_malloc(sizeof(mlx_texture_t) * 5, 0);
	if (!m->all_textures)
		free_all_exit(m, data);
	m->all_textures[0] = mlx_load_png(data->ea);
	if (!m->all_textures[0])
		free_all_exit(m, data);
	m->all_textures[1] = mlx_load_png(data->we);
	if (!m->all_textures[1])
	{
		mlx_delete_texture(m->all_textures[0]);
		free_all_exit(m, data);
	}
	init_textures_2(m, data);
}

void	update_texture(t_wall *w, t_ray *rays, t_map_e *m)
{
	double	angle;

	angle = rays->angle;
	update_angle(&angle);
	if (rays->hit_vertical)
	{
		if (angle >= 90 && angle < 270)
			w->t->texture = m->all_textures[0];
		else
			w->t->texture = m->all_textures[3];
	}
	else
	{
		if (angle >= 0 && angle < 180)
			w->t->texture = m->all_textures[2];
		else
			w->t->texture = m->all_textures[1];
	}
	w->t->arr = (uint32_t *)w->t->texture->pixels;
}
