/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:57:12 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/21 20:08:12 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_wall_values(t_wall *w)
{
	w->distance_to_projection = (W_WIDTH * BLOCK_W / 2)
		/ tan(FOV / 2 * (M_PI / 180));
}

static void	update_wall_values(t_wall *w, t_ray *rays, t_map_e *m)
{
	update_texture(w, rays, m);
	w->distance = rays->distance;
	w->distance = ft_fabs(cos((m->player->angle - rays->angle)
				* (M_PI / 180)) * w->distance);
	w->wall_height = ((w->distance_to_projection * BLOCK_L) / w->distance);
	w->wall_top = (((BLOCK_L * W_HEIGHT) / 2)
			- ((w->wall_height / 2)));
	if (w->wall_top < 0)
		w->wall_top = 0;
	w->wall_bot = absolute_value((BLOCK_L * W_HEIGHT) / 2)
		+ ((w->wall_height / 2));
	if (absolute_value(w->wall_bot) > W_HEIGHT * BLOCK_L)
		w->wall_bot = W_HEIGHT * BLOCK_L;
	w->t->offset_x = (int)((rays->bitmap_offset)
			* (w->t->texture->width / BLOCK_W)) % (w->t->texture->width);
	if (w->t->offset_x < 0)
		w->t->offset_x = 0;
	w->t->scaling_factor = ((double)w->t->texture->height / w->wall_height);
	w->angle = rays->angle;
}

static void	draw_wall(t_wall *w, t_map_e *m, int x)
{
	int	y;
	int	b;

	y = w->wall_top;
	b = w->wall_bot;
	w->t->offset_y = (int)(((w->wall_top - (W_HEIGHT * BLOCK_L / 2)
					+ (w->wall_height / 2))
				* w->t->scaling_factor)) % (w->t->texture->height);
	if (w->t->offset_y < 0)
		w->t->offset_y = 0;
	while (y < b)
	{
		w->t->color = w->t->arr[((int)w->t->offset_y
				* w->t->texture->width) + (int)w->t->offset_x];
		w->t->color = convert_pixel_to_color(w->t->color);
		mlx_put_pixel(m->interface->new_img,
			x, y, w->t->color);
		w->t->offset_y += w->t->scaling_factor;
		y++;
	}
}

void	render_wall(t_map_e *m, t_ray *ray, t_wall *w, int x)
{
	update_wall_values(w, ray, m);
	draw_sky(m, x, w);
	draw_wall(w, m, x);
	draw_floor(w, m, x);
}

void	draw_3d_walls(t_map_e *m)
{
	static t_wall	*w;

	if (!w)
	{
		w = ft_malloc(sizeof(t_wall), 0);
		if (!w)
			exit(1);
		w->t = ft_malloc(sizeof(t_bitmap), 0);
	}
	init_wall_values(w);
	draw_all_walls(m, w);
}
