#ifndef FDF_H
# define FDF_H

/*
************************************ Includes **********************************
*/

# include "libft.h"
# include "fdf_keys.h"
# include <mlx.h>
# include <sys/stat.h>
# include <math.h>
# include <time.h>

/*
************************************ Defines ***********************************
*/

# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define WIN_NAME		"fdf"

# define MLX_INIT_ERR		"mlx_init failed"
# define MLX_NEW_WIN_ERR	"mlx_new_window failed"
# define MLX_NEW_IMG_ERR	"mlx_new_image failed"

/*
************************************ Data **************************************
*/

typedef enum		e_color_types
{
	DEFAULT,
	RED_COLOR,
	GREEN_COLOR,
	BLUE_COLOR,
	RANDOM_COLOR,
	COLOR_TYPES_SIZE
}					t_color_types;

typedef struct		s_point
{
	int32_t			x;
	int32_t			y;
	int32_t			z;
	int32_t			color;
}					t_point;

typedef struct		s_draw_line_variables
{
	int32_t			dx;
	int32_t			dy;
	int32_t			sx;
	int32_t			sy;
	int32_t			err;
	int32_t			e2;
}					t_draw_line_variables;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int32_t			bits_per_pixel;
	int32_t			size_line;
	int32_t			endian;
	t_list			*points;
	uint32_t		x_size;
	uint32_t		y_size;
	t_point			**p;
	const char		*file_name;
	uint32_t		i;
	uint32_t		j;
	char			c;
	int32_t			zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int32_t			x_offset;
	int32_t			y_offset;
	uint8_t			color_type;
}					t_fdf;

/*
******************************* Functions **************************************
*/

void				fdf_init(t_fdf *fdf, const char *file_name);
void				fdf_init_window(t_fdf *fdf);
void				fdf_init_points(t_fdf *fdf);
void				fdf_free(t_fdf *fdf);
void				fdf_point_del(void *content, size_t content_size);
void				fdf_exit(t_fdf *fdf);
void				fdf_perror_exit(const char *message, t_fdf *fdf);
void				fdf_parser_error_exit(t_fdf *fdf,
						uint32_t y, uint32_t x, const char *message);

void				fdf_print_usage(void);

int					fdf_button_event(int key, t_fdf *fdf);
int					fdf_close(t_fdf *fdf);

void				fdf_parser(t_fdf *fdf);
void				fdf_parser_new_line_logic(t_fdf *fdf, t_point *tp);

void				fdf_run(t_fdf *fdf);

void				fdf_draw_line(t_fdf *fdf, t_point p0, t_point p1);

t_point				fdf_get_converted_point(t_fdf *fdf, t_point p);

void				fdf_reset(t_fdf *fdf);

void				fdf_draw(t_fdf *fdf);

void				fdf_rotate_x(t_fdf *fdf, t_point *p);
void				fdf_rotate_y(t_fdf *fdf, t_point *p);
void				fdf_rotate_z(t_fdf *fdf, t_point *p);

#endif
