/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:53:33 by haalouan          #+#    #+#             */
/*   Updated: 2025/01/09 16:16:19 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_so(char **str, t_map *textures)
{
	int		i;
	int		flag;
	int		save;
	char	**save_str;

	i = 0;
	flag = 0;
	save = 0;
	save_str = copy(str);
	while (str && str[i] && str[i][0] != '1')
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (ft_strncmp(save_str[i], "SO", 2) == 0)
		{
			double_check(save_str, textures, i);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures, save_str);
	save_str[save] = escape_spaces(save_str[save]);
	textures->so = put_map(save_str[save], 2);
	free_all_lines(save_str);
}

void	put_no(char **str, t_map *textures)
{
	int		i;
	int		flag;
	int		save;
	char	**save_str;

	i = 0;
	flag = 0;
	save_str = copy(str);
	while (str && str[i] && str[i][0] != '1')
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (ft_strncmp(save_str[i], "NO", 2) == 0)
		{
			if (save_str[i][2] != ' ' && save_str[i][2] != '\t')
				manage_error(str, textures, save_str);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures, save_str);
	save_str[save] = escape_spaces(save_str[save]);
	textures->no = put_map(save_str[save], 2);
	free_all_lines(save_str);
}

void	put_we(char **str, t_map *textures)
{
	int		i;
	int		flag;
	int		save;
	char	**save_str;

	i = 0;
	save_str = copy(str);
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (ft_strncmp(save_str[i], "WE", 2) == 0)
		{
			if (save_str[i][2] != ' ' && save_str[i][2] != '\t')
				manage_error(str, textures, save_str);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures, save_str);
	save_str[save] = escape_spaces(save_str[save]);
	textures->we = put_map(save_str[save], 2);
	free_all_lines(save_str);
}

void	put_ea(char **str, t_map *textures)
{
	int		i;
	int		save;
	int		flag;
	char	**save_str;

	i = 0;
	flag = 0;
	save_str = copy(str);
	while (str && str[i] && str[i][0] != '1')
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (ft_strncmp(save_str[i], "EA", 2) == 0)
		{
			if (save_str[i][2] != ' ' && save_str[i][2] != '\t')
				manage_error(str, textures, save_str);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures, save_str);
	save_str[save] = escape_spaces(save_str[save]);
	textures->ea = put_map(save_str[save], 2);
	free_all_lines(save_str);
}

void	put_f(char **str, t_map *textures)
{
	int		i;
	int		save;
	int		flag;
	char	**save_str;

	i = 0;
	flag = 0;
	save_str = copy(str);
	while (str && str[i] && str[i][0] != '1')
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (ft_strncmp(save_str[i], "F", 1) == 0)
		{
			if (save_str[i][1] != ' ' && save_str[i][1] != '\t')
				manage_error(str, textures, save_str);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures, save_str);
	save_str[save] = escape_spaces(save_str[save]);
	textures->f = put_map(save_str[save], 1);
	free_all_lines(save_str);
}
