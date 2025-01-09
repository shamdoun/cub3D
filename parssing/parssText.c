/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssText.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:43:56 by haalouan          #+#    #+#             */
/*   Updated: 2025/01/09 16:16:52 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_c(char **str, t_map *textures)
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
		if (ft_strncmp(save_str[i], "C", 1) == 0)
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
	textures->c = put_map(save_str[save], 1);
	free_all_lines(save_str);
}

void	put_0_1(char **str, t_map *textures)
{
	int		i;
	char	*save;
	char	*re;
	int		flag_error;
	int		k;

	i = 0;
	k = 0;
	flag_error = 0;
	i = check_map_valid(str);
	textures->map = allocate_map(count_map(str + i));
	while (str && str[i])
	{
		save = ft_strdup(str[i]);
		re = ft_strtrim(save, "\n");
		if (re[0] == '\0')
			flag_error = 1;
		free(save);
		if (flag_error == 0)
			textures->map[k] = ft_strdup(re);
		handele_this_error(flag_error, re, str, textures);
		free(re);
		k++;
		i++;
	}
}

void	parsse_textures(char **str, t_map *textures)
{
	put_no(str, textures);
	put_so(str, textures);
	put_we(str, textures);
	put_ea(str, textures);
	put_f(str, textures);
	put_c(str, textures);
	check_f_c(str, textures);
	put_0_1(str, textures);
}

char	*escape_spaces(char *str)
{
	char	*s;
	char	*re;

	s = ft_strtrim(str, " ");
	free(str);
	re = ft_strtrim(s, "\t");
	free(s);
	return (re);
}

char	*put_map(char *str, int plus)
{
	char	*s;
	char	*re;
	int		i;

	s = NULL;
	i = plus;
	while (str && str[i] && str[i] == ' ' && str[i] == '\t')
		i++;
	s = ft_strdup(str + i);
	re = ft_strtrim(s, "\n");
	free(s);
	re = escape_spaces(re);
	return (re);
}
