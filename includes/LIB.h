/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:54:21 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 18:01:33 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "libft/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <math.h>

# define RESOLUTION_L 900
# define RESOLUTION_H 600
# define BUFFERSIZ 1024
# define NAME_WINDOW "Cub3d"
# define ROUGE 0xFFFF0000
# define VERTE 0xFF00FF00
# define BLEU 0xFF0000FF
# define PI 3.14159265359
# define A 97
# define W 119
# define S 115
# define D 100
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define SHIFT 65505
# define ESC 65307
# define WALL_SIZE 70
# define SPEEDRUN 0.03
# define SPEEDROTATE 0.07

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_img
{
	char	*data;
	void	*img;
	int		bpp;
	int		endian;
	int		size_line;
	int		width;
	int		height;
}				t_img;

typedef struct s_game
{
	//------------------------------- for file
	int		total_lu;// de bytes lu par read pour
	int		index;// initaliser a after texture
	char	**texture_name;// FREEE OUBLIE PAS
	char	**split;// NE PAS OUBLIER DE FREE
	int		ceiling;
	int		floor;
	//-----------------------Chemins des textures
	char	*no;
	char	*so;//-> A NE SURTOUT PAS FREE CAR CES DES POINTEURS VERS MON SPLIT
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	//--------------------------------- MAP
	int		map_height;
	int		flags;
	//---------------------------------
	char	**map;// dans un tableau de tableau avec axe x et y
	t_point	pos_player;
	t_point	current;
	double	player_angle;
	char	angle_initiale;
	//utiliser pour economiser de l'espace dans mes fonctions
	double	r_x;
	double	r_y;
	double	dist_rayon;
	double	wall_size;
	int		finish;
	int		start_y;
	int		choice;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	key_rotate_left;
	bool	key_rotate_right;
	bool	key_esc;
	bool	key_speed;
	//-------------------------------- RENDER
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	frame;
	t_img	no_t;
	t_img	so_t;
	t_img	we_t;
	t_img	ea_t;
	t_img	*tab_img[4];
}				t_game;

/*
=================================
			PARSING -> adil
=================================
*/
void	info_map(t_game *data);

int		check_elements(t_game *game);

int		main_parsing(char *file, t_game *data);

int		ft_line_empty(char *line);

int		ft_init_texture(t_game *d);

int		ft_file_empty(char *file);

int		chop_texture(t_game *data, int i, int j, int fd);

int		check_already_exist(t_game *data);

int		ft_init_split(char *file, t_game *data, int fd, int lettre_lu);

int		parse_map(t_game *data);

int		limit_number_rgb(char *str, int i, int j, int count);

int		ft_position(t_game *game);

char	**copy_map(char **map, int height);

void	fill(t_game *game, char **map_copy, t_point current);

/*
=============================================
				FREE
=============================================
*/

void	free_data(t_game *data);
void	free_tab(char **tab);
/*
============================================
			RENDER -> RECASTING
============================================
*/

int		init_my_mlx(t_game *data);

/*
===============================================
					GAME
===============================================
*/

void	ft_init_data(t_game *data);

void	put_pixel(int x, int y, int color, t_game *data);
void	clean_img(t_game *data);
void	draw_square(int x, int y, int color, t_game *data);
void	map_render(t_game *data);

void	init_hook(t_game *data);
int		key_reset(int keypress, t_game *data);
int		key_press(int keypress, t_game *data);
void	move_player(t_game *data, double cos_a, double sin_a, double speed);
int		no_number(char *line);
int		check_xpm(t_game *data);
int		check_extension(char *file, const char *extension);
double	v_absolue(double nb);
int		check_exist(t_game *data, int i, int j);
void	load_texture(t_game *data);
void	floor_and_ceiling(t_game *data);
int		ft_get_color_key(char *str);
double	get_distance_rayon(double x_1, double x_2, double y_1, double y_2);
void	what_texture(t_game *d, double start_angle);
void	info_recast(t_game *d, double start_angle);
int		ft_do_x(t_game *d);
int		ft_croix_rouge(t_game *data);

#endif