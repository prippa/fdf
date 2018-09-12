/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:11 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define FPF_BUF_SIZE 1024

typedef enum			e_fpf_size_flags
{
	SF_H = 1,
	SF_HH,
	SF_L,
	SF_LL,
	SF_J,
	SF_Z
}						t_fpf_size_flags;

typedef enum			e_fpf_flags
{
	F_MINUS,
	F_PLUS,
	F_SPACE,
	F_SHARP,
	F_ZERO,
	F_DOT,
	F_COLOR,
	F_UPERCASE,
	FLAG_SIZE
}						t_fpf_flags;

typedef struct			s_printf
{
	va_list				args;
	const char			*format;
	char				*str;
	int					fd;
	char				buf[FPF_BUF_SIZE + 1];
	int					buflen;
	char				f[FLAG_SIZE];
	int					color;
	int					width;
	int					precision;
	int					size_flag;
	char				type;
	int					len;
}						t_printf;

# define COLOR_RESET 	"\x1B[0m"
# define RED   			"\x1B[31m"
# define YELLOW   		"\x1B[33m"
# define GREEN   		"\x1B[32m"
# define CYAN   		"\x1B[36m"
# define BLUE   		"\x1B[34m"
# define MAGENTA   		"\x1B[35m"
# define WHITE 			"\x1B[37m"
# define GRAY			"\e[90m"

# define BOLD_GRAY 		"\033[1;30m"
# define BOLD_RED 		"\033[1;31m"
# define BOLD_GREEN 	"\033[1;32m"
# define BOLD_YELLOW 	"\033[1;33m"
# define BOLD_BLUE 		"\033[1;34m"
# define BOLD_MAGENTA 	"\033[1;35m"
# define BOLD_CYAN 		"\033[1;36m"
# define BOLD_WHITE 	"\033[1;39m"

# define BACK_RED_BLACK		"\e[30;41m"
# define BACK_GREEN_BLACK	"\e[30;42m"
# define BACK_BLUE_BLACK	"\e[30;44m"
# define BACK_CYAN_BLACK	"\e[30;46m"
# define BACK_GRAY_BLACK	"\e[30;100m"

# define BACK_RED_WHITE		"\e[1;97;41m"
# define BACK_GREEN_WHITE	"\e[1;97;42m"
# define BACK_BLUE_WHITE	"\e[1;97;44m"
# define BACK_CYAN_WHITE	"\e[1;97;46m"

typedef enum			e_fpf_colors
{
	F_GREEN = 1,
	F_BLUE,
	F_RED,
	F_CYAN,
	F_BOLD_GREEN,
	F_BOLD_BLUE,
	F_BOLD_RED,
	F_BOLD_CYAN,
	F_YELLOW,
	F_MAGENTA,
	F_WHITE,
	F_GRAY,
	F_BOLD_GRAY,
	F_BOLD_YELLOW,
	F_BOLD_MAGENTA,
	F_BOLD_WHITE,
	F_BACK_GREEN_BLACK,
	F_BACK_BLUE_BLACK,
	F_BACK_RED_BLACK,
	F_BACK_CYAN_BLACK,
	F_BACK_GRAY_BLACK,
	F_BACK_GREEN_WHITE,
	F_BACK_BLUE_WHITE,
	F_BACK_RED_WHITE,
	F_BACK_CYAN_WHITE
}						t_fpf_colors;

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
void					fpf_cat_char(t_printf *fpf, char c);
void					fpf_cat_str(t_printf *fpf, const char *src);
void					fpf_cat_char_len(t_printf *fpf, int n, char c);
void					fpf_cat_str_len(t_printf *fpf, const char *src, int n);
void					fpf_parser(t_printf *fpf);
signed long long int	fpf_conv_sig_int(t_printf *fpf);
unsigned long long int	fpf_conv_unsig_int(t_printf *fpf);
void					fpf_malloc_error_exit(void);
void					fpf_get_type(t_printf *fpf);
char					*fpf_wstr_to_str(wchar_t *ws);
void					fpf_init_random_char(t_printf *fpf);
void					fpf_output_c(t_printf *fpf);
void					fpf_output_d(t_printf *fpf);
void					fpf_output_ox(t_printf *fpf);
void					fpf_output_p(t_printf *fpf);
void					fpf_output_s(t_printf *fpf);
void					fpf_output_u(t_printf *fpf);
void					fpf_set_color(t_printf *fpf);
void					fpf_before_processing_data(t_printf *fpf);
void					fpf_after_processing_data(t_printf *fpf);

#endif
