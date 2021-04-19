/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:19:05 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:29:11 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.141592653589793238462643383279502884197169399375105820974944
# define TWO_PI 6.28318531

# include "./minilibx-linux/mlx.h"
# include "./GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_dbxy
{
	double		x;
	double		y;
}				t_dbxy;

typedef struct	s_slope
{
	int			slope;
	int			slope_sign;
}				t_slope;

typedef struct	s_player
{
	int			x;
	int			y;
	char		direction;
	int			width;
	int			height;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	double		walk_speed;
	double		turn_speed;
	double		fov_angle;
	int			is_mov_right;
}				t_player;

typedef struct	s_rays
{
	double		num_of;
	double		size_of;
	double		distance;
	double		wall_hit_x;
	double		wall_hit_y;
	double		wall_hit_content;
	double		was_hit_vertical;
	double		ray_angle;
	int			is_facing_down;
	int			is_facing_up;
	int			is_facing_left;
	int			is_facing_right;
	double		horz_hit_distance;
	double		vert_hit_distance;
	double		horz_wall_hit_x;
	double		horz_wall_hit_y;
	double		vert_wall_hit_x;
	double		vert_wall_hit_y;
	int			column_id;
}				t_rays;

typedef struct	s_sprites
{
	double		x;
	double		y;
	double		dis;
	double		angle;
	int			is_visible;
	double		h;
	double		w;
	double		top_y;
	double		bottom_y;
	double		left_x;
	double		right_x;
}				t_sprites;

typedef struct	s_textures
{
	char		*img;
	void		*mlx;
	int			w;
	int			h;
	int			bpp;
	int			line_length;
	int			endian;
	int			set;
}				t_textures;

typedef struct	s_vars
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_h;
	int			win_w;
	char		*window_title;
	int			r_ceiling;
	int			g_ceiling;
	int			b_ceiling;
	int			rgb_ceiling;
	int			r_floor;
	int			g_floor;
	int			b_floor;
	int			rgb_floor;
	char		*tex_path[5];
	int			up;
	int			down;
	int			left;
	int			right;
	char		*map_path;
	int			map_width;
	int			map_height;
	char		**map;
	int			tile_x;
	int			tile_y;
	double		minimap_scale;
	int			color;
	int			num_of_sprites;
	int			sprite_id;
	double		*wall_distances;
	int			save;
	double		ray_angle;
	int			check;
	double		wallprojh;
	int			counter;
	t_player	player;
	t_rays		rays;
	t_textures	*tex;
	t_sprites	*sprite;
	t_xy		xy;
	t_slope		slope;
}				t_vars;

int				main(int argc, char **argv);
void			ft_init_struct(t_vars *strct);
int				ft_init_window(t_vars *strct);
void			ft_mlx_pixel_put(t_vars *strct, int x, int y, int color);
void			ft_square(t_vars *strct, int h, int w);
void			ft_empty_circle(t_vars *strct, int x, int y, int radius,
					int color);
void			ft_filled_circle(t_vars *strct, int x, int y, int radius,
					int color);
int				key_press(int keycode, t_vars *strct);
int				key_release(int keycode, t_vars *strct);
int				close_program(t_vars *strct);
int				ft_move(t_vars *strct);
void			ft_putendl_fd(char *s, int fd);
int				ft_check_argument(char *s);
int				ft_check_args(t_vars *vars, int argc, char **argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_check_input(t_vars *strct);
void			ft_black_screen(t_vars *strct);
int				ft_eval_line(char *line, t_vars *strct);
int				ft_resolution(char *str, t_vars *strct);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
int				ft_colors(char *str, t_vars *strct);
int				ft_textures(char *str, t_vars *strct);
int				ft_check_map(t_vars *strct);
int				ft_render_map(t_vars *strct);
int				ft_render_player(t_vars *strct);
int				ft_draw_line(t_vars *strct, int x2, int y2);
int				ft_has_wall_at(t_vars *strct, double x, double y);
void			cast_all_rays(t_vars *strct);
void			ft_init_rays(t_vars *strct);
double			ft_normalize_angle(double angle);
double			ft_distance_between_points(double x1, double y1, double x2,
					double y2);
void			cast_3d_rays(t_vars *strct);
int				ft_load_textures(t_vars *strct, int i);
void			ft_draw_texture(t_vars *strct, int top_pixel, int bottom_pixel,
					double wall_strip_height, int i);
void			ft_init_sprites(t_vars *strct);
void			ft_render_sprites(t_vars *strct);
void			ft_draw_sprite(t_vars *strct, int x, int i);
int				create_rgb(int t, int r, int g, int b);
void			rgb_maker(t_vars *strct);
int				save_bmp_file(t_vars *strct);
void			ft_bzero(void *s, size_t n);
int				ft_init_image(t_vars *strct);
void			calc_sprite(t_vars *strct, int i, double perp, double dis);
int				nbr_free(char **nbr);
int				dx_0(t_vars *strct, t_xy *xy, t_xy *xy2, t_xy *dxy);
int				dy_0(t_vars *strct, t_xy *xy, t_xy *xy2, t_xy *dxy);
void			set_strct(t_vars *strct, t_xy *xy, t_xy *xy2);
void			calc_slope(t_vars *strct, t_xy *dxy, t_xy *xy);
void			draw(t_vars *strct, t_xy *xy, t_xy *xy2);
int				ft_which_texture(t_vars *strct, double ray_angle);
void			ft_large_slope(t_vars *strct, int slope_sign,
					t_xy *xy1, t_xy *xy2);
void			ft_small_slope(t_vars *strct, int slope_sign,
					t_xy *xy1, t_xy *xy2);
void			ft_render_3d_rays(t_vars *strct, double ray_angle);
void			ft_distance_calc(t_vars *strct, double ray_angle);
void			ft_vertical_check(t_vars *strct, double ray_angle);
void			set_xy_colors(t_vars *strct, int i, int wall_bottom_pixel);
void			ft_close_free_gnl(int fd, char *line);
void			ft_drtex(t_vars *strct, int top_p, int bot_p, int i);
void			ft_init_rays(t_vars *strct);
int				ft_1(t_vars *strct, char *line, int i);
int				ft_2(t_vars *strct, char *line, int i);
int				ft_3(t_vars *strct, char *line, int i);
int				ft_4(t_vars *strct, char *line, int i);
int				ft_5(t_vars *strct, char *line, int i);
void			ft_horizontal_check(t_vars *strct, double ray_angle);
void			init_vert(t_dbxy *intercept, t_dbxy *step,
					t_dbxy *next_touch, t_vars *strct);
void			ft_eval_aux1(t_vars *strct, char *line);
int				ft_first_if(t_vars *strct, char *line, int line_nbr, int fd);
int				ft_map_and_dir(t_vars *strct);
void			ft_close_free_gnl(int fd, char *line);
int				ft_last_line(t_vars *strct, char *line, int fd, int line_nbr);
int				ft_get_direction(t_vars *strct);
int				ft_map_x(t_vars *strct, int i, int j);
int				ft_map_0(t_vars *strct, int i, int j);
int				ft_map_is_valid(t_vars *strct);
int				ft_map_aux1(char *str, int i);
void			ft_map_aux2(t_vars *strct, int line_nbr, int i);
void			ft_map_aux3(t_vars *strct, char *str, int line_nbr, int i);
char			*ft_map_aux4(t_vars *strct, char *temp, char *str, int i);
int				ft_map_aux5(t_vars *strct, char *temp, char *str, int line_nbr);
int				ft_map(char *str, t_vars *strct, int line_nbr);
double			ft_normalize_angle(double angle);
int				ft_vert_while(t_dbxy *check, t_dbxy *next_touch,
					t_vars *strct, t_dbxy *step);
int				ft_game(t_vars *strct);
void			ft_render_save(t_vars *strct);

#endif
