/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:15:31 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 18:06:20 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all_lines(char **all_lines)
{
	int	i;

	i = 0;
	while (all_lines && all_lines[i])
	{
		if (all_lines[i])
			free(all_lines[i]);
		i++;
	}
	if (all_lines)
		free(all_lines);
}

void	free_map(t_map *Map)
{
	int	i;

	i = 0;
	if (Map->c)
		free(Map->c);
	if (Map->f)
		free(Map->f);
	if (Map->no)
		free(Map->no);
	if (Map->so)
		free(Map->so);
	if (Map->we)
		free(Map->we);
	if (Map->ea)
		free(Map->ea);
	if (Map->map)
		free_all_lines(Map->map);
	if (Map)
		free(Map);
}

void	double_check(char **str, t_map *textures, int i)
{
	if (str[i][2] != ' ' && str[i][2] != '\t')
		manage_error(str, textures);
}

void	handele_this_error(int flag_error,
	char *re, char **str, t_map *textures)
{
	if (flag_error == 1 && re[0] != '\0')
		manage_error(str, textures);
}
