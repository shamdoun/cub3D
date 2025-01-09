/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:18:29 by haalouan          #+#    #+#             */
/*   Updated: 2025/01/09 16:16:35 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_f_c(char **str, t_map *textures)
{
	int		i;
	char	**save_str;

	i = 0;
	save_str = copy(str);
	while (str && str[i])
	{
		save_str[i] = escape_spaces(save_str[i]);
		if (save_str[i][0] == 'C' || save_str[i][0] == 'F')
			continue_check_f_c(save_str, textures, save_str[i]);
		i++;
	}
	free_all_lines(save_str);
}

void	continue_check_f_c(char **str, t_map *textures, char *s)
{
	int	j;
	int	flag;
	int	vergul;

	j = 0;
	flag = 0;
	vergul = 0;
	while (s && s[j] && s[j] != '\n')
	{
		if (s[j] == '-' || s[j] == '+')
			manage_error(str, textures, NULL);
		if (s[j] == ',')
			vergul++;
		if (s[j] <= '9' && s[j] >= '0')
		{
			vergul += continue_f_c(str, textures, s, &j);
			flag++;
		}
		j++;
	}
	if (flag != 3 || vergul != 2)
		manage_error(str, textures, NULL);
}

void	continue_f_c_v2(char **str, t_map *textures, char *save)
{
	int	start;

	start = 0;
	while (save && save[start])
	{
		if (save[start] > '9' || save[start] < '0')
		{
			free(save);
			manage_error(str, textures, NULL);
		}
		start++;
	}
}

int	continue_f_c(char **str, t_map *textures, char *s, int *j)
{
	int		start;
	int		end;
	int		res;
	char	*save;
	int		vergul;

	start = *j;
	vergul = 0;
	while (s[*j] && s[*j] != '\n' && s[*j] != ',')
	{
		if (s[*j] == ' ' || s[*j] == '\t')
			manage_error(str, textures, NULL);
		(*j)++;
	}
	if (s[*j] == ',')
		vergul++;
	end = *j - 1;
	save = ft_copy(s, start, end);
	continue_f_c_v2(str, textures, save);
	res = ft_atoi(save);
	free(save);
	if (res < 0 || res > 255)
		manage_error(str, textures, NULL);
	return (vergul);
}

char	*ft_copy(char *str, size_t start, size_t end)
{
	int		len;
	char	*new_str;
	int		i;

	len = end - start + 1;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
	{
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
