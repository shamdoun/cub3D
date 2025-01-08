/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:52:54 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/21 20:05:31 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "sources/get_next_line/get_next_line.h"
# include "sources/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "/Users/haalouan/Desktop/MLX42/include/MLX42/MLX42.h"


# define BLOCK_W 64
# define BLOCK_L 64
# define W_HEIGHT 20
# define M_M_H 6
# define M_M_W 6
# define W_WIDTH 20
# define FOV 60
# define BORDER_WIDTH 4

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
}	t_map;

typedef struct mlx_v
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*new_img;
	char		*title;
}	t_mlx;

typedef struct ray_calc_v
{
	double	x_inter;
	double	y_inter;
	double	ax;
	double	ay;
	double	angle;
	double	tan_angle;
	double	verif_y;
	double	verif_x;
}	t_ray_calc;

typedef struct line_vector
{
	long	line_length;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_line;

typedef struct player_v
{
	double	x_p;
	double	y_p;
	double	old_x;
	double	old_y;
	double	angle;
	int		rotation_speed;
}	t_player;

typedef struct map_v
{
	char					*type;
	int						flag;
	int						open;
	int						click;
	struct mlx_v			*interface;
	int						**map_values;
	char					**m_values;
	mlx_texture_t			**all_textures;
	struct player_v			*player;
	int						width;
	int						height;
	uint32_t				floor;
	uint32_t				ceiling;
	struct minimap_v		*minimap;
	int						my_x;
	int						dis;
	int						my_y;
}	t_map_e;

typedef struct ray_v
{
	double				distance;
	int					hit_vertical;
	double				angle;
	double				x;
	double				my_y;
	double				my_x;
	double				bitmap_offset;
	double				tan;
	struct ray_v		*next;
	struct ray_v		*previous;
}	t_ray;

typedef struct bitmap_v
{
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			offset_x;
	double			offset_y;
	double			scaling_factor;
	uint32_t		color;
}	t_bitmap;

typedef struct wall_v
{
	double			distance;
	double			distance_to_projection;
	double			height;
	double			wall_height;
	double			wall_top;
	double			wall_bot;
	struct bitmap_v	*t;
	double			angle;
	struct wall_v	*next;
}	t_wall;

typedef struct data_v
{
	void			*data;
	struct data_v	*next;
}	t_data;

typedef struct minimap_v
{
	double	begin_i;
	double	begin_j;
	double	i2;
	double	j2;
}	t_minimap;
void	init_all_values(t_map_e *m, t_map *data);
void	init_textures(t_map_e *m, t_map *data);
void	update_texture(t_wall *w, t_ray *rays, t_map_e *m);
void	move_right(t_player *p, char **mapValues);
void	move_left(t_player *p, char **mapValues);
void	move_down(t_player *p, char **mapValues);
void	move_up(t_player *p, char **mapValues);
void	key_func(void *param);
void	terminate_game(t_map_e *m);
int		get_rgba(int r, int g, int b, int a);
double	cast_to_window(double old_v, int o_l, int o_m, int flag);
void	apply_dda_algorithm(t_map_e *m);
void	draw_player(t_map_e *map);
void	apply_dda_algorithm(t_map_e *m);
void	draw_3d_walls(t_map_e *m);
void	ft_lstadd_back(t_ray **lst, t_ray *new);
t_ray	*ft_lstnew(double x);
void	draw_mini_map(t_map_e *m);
int		row_empty(char *s);
int		wall_contact(t_player *p, char **mapValues);
void	init_player_instance(t_map_e *map3d, t_map *data);
void	my_put_mlx(t_map_e *map, int x, int y);
int		convert_pixel_to_color(uint32_t color);
void	draw_sky(t_map_e *m, int x, t_wall *w);
void	draw_floor(t_wall *w, t_map_e *m, int x);
void	draw_sky(t_map_e *m, int x, t_wall *w);
void	draw_floor(t_wall *w, t_map_e *m, int x);
void	apply_dda_algorithm(t_map_e *m);
int		ray_is_facing_left(double angle);
int		ray_is_facing_down(double angle);
double	calculate_magnitude(t_player *player, double x, double y);
void	draw_line(t_map_e *m, double angle, long h_distance);
double	find_horizontal_distance(t_map_e *m, t_ray **h, double angle);
double	find_vertical_distance(t_map_e *m, t_ray **v, double angle);
void	update_angle(double *angle);
long	find_min(long a, long b);
void	ft_lstadd_a_back(t_data **lst, t_data *new);
t_data	*ft_lstnew_ad(void *address);
int		mouvement_is_blocked(t_map_e *m, int map_y, int map_x, double angle);
void	init_player_position(t_player *p, int i, int j, char direction);
void	draw_all_walls(t_map_e *m, t_wall *w);
void	render_wall(t_map_e *m, t_ray *ray, t_wall *w, int x);
void	free_all_exit(t_map_e *map, t_map *data);
void	close_function(void *param);
void	allocate_cal_struc(t_ray_calc	**cal);
double ft_fabs(double value);
int		mouvement_is_blocked_d(t_map_e *m, int map_y, int map_x, double angle);
void	open_door(struct mlx_key_data key, void *param);
int		parsse_args(char *str);
t_map	*parssing(int arc, char **arv);
char	**allocate_all_lines(int fd, char **arv);
char	**parsse_all_lines(char **str);
char	**allocate_str(char **str);
void	parsse_textures(char **str, t_map *textures);
t_map	*allocate_textures(void);
void	put_0_1(char **str, t_map *textures);
int		count_map(char **str);
char	**allocate_map(int i);
void	check_map(char **str);
char	*escape_spaces(char *str);
int		check_map_valid(char **map);
void	print_textures(t_map *textures);
void	free_all_lines(char **all_lines);
void	free_map(t_map *Map);
void	check_valid_for0(char **all_lines, t_map *textures, int i, int k);
void	check_valid_for_player(char **all_lines, t_map *textures, int i, int k);
void	check_end_line(char **all_lines, t_map *textures, int k);
void	protecte_map(char **all_lines, t_map *textures, int i, int k);
void	check_empty_line(char **all_lines, t_map *textures);
void	parsse_map(char **all_lines, t_map *textures);
void	check_dup(char **all_lines, t_map *textures);
void	manage_error(char **str, t_map *textures);
void	put_c(char **str, t_map *textures);
void	put_0_1(char **str, t_map *textures);
void	parsse_textures(char **str, t_map *textures);
char	*escape_spaces(char *str);
char	*put_map(char *str, int plus);
void	put_so(char **str, t_map *textures);
void	put_no(char **str, t_map *textures);
void	put_we(char **str, t_map *textures);
void	put_ea(char **str, t_map *textures);
void	put_f(char **str, t_map *textures);
void	check_dup(char **all_lines, t_map *textures);
void	protecte_map(char **all_lines, t_map *textures, int i, int k);
void	check_f_c(char **str, t_map *textures);
void	continue_check_f_c(char **str, t_map *textures, char *s);
void	continue_f_c(char **str, t_map *textures, char *s, int *j);
char	*ft_copy(char *str, size_t start, size_t end);
void	double_check(char **str, t_map *textures, int i);
void	handele_this_error(int flag_error, char *re, char **str, t_map *textures);

#endif