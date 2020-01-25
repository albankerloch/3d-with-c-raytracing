/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:00:52 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 15:44:06 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_data
{
	void		*connexion;
	void		*window;
	void		*image2;
	void		**imaget;
	int			**strt;
	void		*fond;
	char		*fut;
	int			l;
	int			h;
	int			l2;
	int			h2;
	int			size;
	int			endian;
	int			bitpp;
	int			endian2;
	int			size2;
	int			bitpp2;
	int			taille;
	int			x;
	int			y;
	int			x2;
	int			y2;
	double		angle;
	int			**tab;
	int			*str2;
	int			*strp;
	void		**images;
	int			l_tab;
	int			h_tab;
	int			color_roof;
	int			color_floor;
	char		**texture;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			axe;
	int			life;
	char		orientation;
	int			check[10];
}				t_data;

typedef struct	s_coordinate
{
	int			h3_2;
	int			t_2;
	int			h3;
	int			t3;
	int			t;
	double		xb;
	double		yb;
	double		xa;
	double		ya;
	double		alpha;
	double		alpha2;
	double		a;
	int			ixa;
	int			iya;
	int			ix;
	int			iy;
	int			ixb;
	int			iyb;
	int			side;
	int			up;
	int			delta;
	int			delta2;
	int			exp;
	int			sprite;
	double		xt;
	double		yt;
	int			ixt;
	int			iyt;
	int			u;
	int			u2;
	int			k;
}				t_coordinate;

void			ft_print_tab(t_data *d);
int				**ft_rotate(t_data *d, char c);
char			*ft_strdup(const char *src);
int				ft_atoi_base(char *str, char *base);
int				ft_atoi(const char *str);
int				ft_parsing(t_data *d, char *name);
int				get_next_line(int fd, char **line);
char			*ft_substr(char *s, int start, int len, int i);
int				ft_strlen(const char *str);
char			*ft_catbuff(char *buffer, char *line, int start, int end);
int				ft_update(t_data *d, int option);
void			ft_rendu(t_coordinate *c, t_data *d);
int				deal_key(int key, t_data *param);
int				ft_check_left(t_data *d, t_coordinate *c);
int				ft_check_right(t_data *d, t_coordinate *c);
int				ft_isspace(char c);
int				ft_exit(t_data *d);
void			ft_fill_init(t_data *d);
void			ft_rendu_texture(t_coordinate *c, t_data *d);
int				ft_export(char *path, t_data *d);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_init(t_data *d, t_coordinate *c);
char			ft_check_next(t_coordinate *c);
void			ft_fill_s(int t1, int t2, int t3, char s[9]);
int				ft_convert_color(char *line);
int				ft_param(char *line, t_data *d);
void			ft_exit_error(t_data *d);
int				**ft_create_tab(char *ft, t_data *d);
void			ft_collision(t_data *d, t_coordinate *c, int y2, int x2);
void			ft_convert(int axe, t_coordinate *c);
void			ft_init_t_coordinates(int axe, t_coordinate *c);
void			ft_exit_malloc(t_data *d, int code);
int				ft_exit_line(t_data *d, char *line);

#endif
