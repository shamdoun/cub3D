/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:53:35 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/21 19:58:47 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	start_game(t_map *data)
{
	t_map_e	*map;

	map = (t_map_e *)malloc(sizeof(t_map_e));
	if (!map)
	{
		free_map(data);
		exit (1);
	}
	init_all_values(map, data);
	draw_mini_map(map);
	if (mlx_image_to_window(map->interface->mlx_ptr,
			map->interface->new_img, 0, 0))
		free_all_exit(map, data);
	mlx_loop_hook(map->interface->mlx_ptr, &key_func, map);
	mlx_close_hook(map->interface->mlx_ptr, &close_function, map);
	mlx_loop(map->interface->mlx_ptr);
	mlx_terminate(map->interface->mlx_ptr);
	free(map);
	ft_malloc(0, 1);
}

int	main(int arc, char **arv)
{
	t_map	*text;

	text = parssing(arc, arv);
	start_game(text);
	free_map(text);
	return (0);
}
