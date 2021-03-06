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

NAME		=	fdf
FLAGS		= 	-Wall -Werror -Wextra
MLXFLAGS 	=	-lmlx -framework OpenGL -framework AppKit
CC			=	gcc

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_FDF	=	fdf.h fdf_keys.h fdf_messages.h

#-------------------------- Source files ---------------------------------------
C_FDF		= 	main.c fdf_parser.c fdf_init.c fdf_exit.c fdf_rotates.c\
				fdf_events_control.c fdf_draw.c fdf_draw_line.c fdf_free.c\


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_FDF:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))

INC_FDF 	= 	$(addprefix $(DIR_INC), $(HEAD_FDF))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_FDF)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files fdf ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files fdf ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
