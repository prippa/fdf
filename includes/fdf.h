#ifndef FDF_H
# define FDF_H

/*
************************************ Includes **********************************
*/

# include "libft.h"
# include "fdf_keys.h"
# include <mlx.h>
# include <sys/stat.h>

/*
************************************ Defines ***********************************
*/

# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define WIN_NAME		"fdf"

# define MLX_INIT_ERR		"mlx_init failed"
# define MLX_NEW_WIN_ERR	"mlx_new_window failed"

/*
************************************ Data **************************************
*/

typedef struct		s_point
{
	int32_t			x;
	int32_t			y;
	int32_t			z;
	uint32_t		color;
}					t_point;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_list2			*p_start;
	t_list2			*p_end;
	const char		*file_name;
	uint32_t		i;
	char			c;
}					t_fdf;

/*
******************************* Functions **************************************
*/

void				fdf_init(t_fdf *fdf, const char *file_name);
void				fdf_window_init(t_fdf *fdf);
void				fdf_free(t_fdf *fdf);
void				fdf_exit(t_fdf *fdf);
void				fdf_perror_exit(const char *message, t_fdf *fdf);
void				fdf_parser_error_exit(t_fdf *fdf,
						uint32_t y, uint32_t x, const char *message);

void				fdf_print_usage(void);

int					fdf_button_event(int key, t_fdf *fdf);
int					fdf_close(t_fdf *fdf);

void				fdf_parser(t_fdf *fdf);

void				fdf_run(t_fdf *fdf);

#endif
