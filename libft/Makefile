# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc -g

DIR_INC		=	./includes/
DIR_LIBC	=	./libc/
DIR_FPF		=	./printf/
DIR_OBJ		= 	./obj/

HEAD_LIBC	=	libft.h
HEAD_FPF	=	ft_printf.h

C_LIBC		= 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c\
			ft_str_is_alpha.c ft_str_is_digit.c ft_str_is_lower.c ft_str_is_upper.c\
			ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
			ft_strtrim.c ft_tolower.c ft_str_to_lower.c ft_str_to_upper.c\
			ft_toupper.c get_next_line.c ft_arrdel.c ft_arrlen.c ft_nbrlen.c\
			ft_clear.c ft_arrnew.c ft_putarr.c ft_putarr_fd.c ft_lstpop.c\
			ft_memrev.c ft_strjoin_free.c ft_memjoin_free.c ft_perror_exit.c\

C_FPF		= 	ft_printf.c fpf_cat_data.c fpf_parser.c fpf_trash.c\
				fpf_parser_get_type.c fpf_conversions.c fpf_unicode.c\
				fpf_output_sc.c fpf_output_d.c fpf_output_u.c\
				fpf_output_ox.c fpf_output_p.c fpf_colors.c fpf_bonus_flags.c


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_LIBC:.c=.o) $(C_FPF:.c=.o))

INC 		= 	$(addprefix -I,$(DIR_INC))
INC_LIBC 	= 	$(addprefix $(DIR_INC), $(HEAD_LIBC))
INC_FPF 	= 	$(addprefix $(DIR_INC), $(HEAD_FPF))


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_LIBC)%.c $(INC_LIBC)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: $(DIR_FPF)%.c $(INC_FPF)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files libft ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files libft ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
