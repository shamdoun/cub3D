/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:28 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 18:06:20 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**put_all_lines(char **str, char **arv)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(arv[1], O_RDONLY);
	if (fd < 0)
		exit(printf("READ FAILED\n"));
	line = get_next_line(fd);
	while (line)
	{
		str[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (str);
}

char	**allocate_all_lines(int fd, char **arv)
{
	char	**all_lines;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	all_lines = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!all_lines)
		exit(EXIT_FAILURE);
	while (j <= i)
		all_lines[j++] = NULL;
	all_lines = put_all_lines(all_lines, arv);
	return (all_lines);
}

char	**allocate_str(char **str)
{
	int		i;
	int		j;
	char	**s;

	s = NULL;
	i = 0;
	j = 0;
	while (str && str[i])
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!s)
		exit(EXIT_FAILURE);
	while (j <= i)
		s[j++] = NULL;
	return (s);
}

t_map	*allocate_textures(void)
{
	t_map	*textures;

	textures = NULL;
	textures = (t_map *)malloc(sizeof(t_map) + 1);
	if (!textures)
		exit(EXIT_FAILURE);
	textures->map = NULL;
	textures->c = NULL;
	textures->f = NULL;
	textures->no = NULL;
	textures->so = NULL;
	textures->ea = NULL;
	textures->we = NULL;
	return (textures);
}

int	check_if_reach_map(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		if (ft_strncmp(str[i], "NO", 2) == 0 || ft_strncmp(str[i], "SO", 2) == 0
			|| ft_strncmp(str[i], "WE", 2) == 0
			|| ft_strncmp(str[i], "EA", 2) == 0
			|| ft_strncmp(str[i], "F", 1) == 0
			|| ft_strncmp(str[i], "C", 1) == 0)
			return (1);
		i++;
	}
	return (0);
}
