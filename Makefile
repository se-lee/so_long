NAME	= so_long
HEADER	= so_long.h

INC		= include
SRC_DIR	= srcs
OBJ_DIR	= objs
SRC		=	map_read.c\
			main.c\
			map_check.c\
			map_draw.c\
			map_coordinates.c\
			move_key.c\
			get_next_line.c\
			exit_game.c\
			free.c\

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIBFT	= libft
LIBFT_FILE = $(LIBFT)/libft.a
RM		= rm -rf

CC		= cc
CFLAGS	= #-Wall -Wextra -Werror
CLIB	= -I ./minilibx_mms_20210621 -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework AppKit

#CLIB	= -I ./minilibx_mms_20210621 -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

all:	init $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(LIBFT)/libft.h
	$(CC) $(CFLAGS) -c $< -Ilibft -o $@

$(NAME):	$(OBJS) $(LIBFT_FILE)
	$(CC) $(CLFAGS) $(CLIB) $(SRCS) -I $(INC) $(LIBFT_FILE) -o $(NAME)
#install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(LIBFT_FILE):	init

init:
	@ mkdir -p objs
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	@ $(RM) objs
	rm -rf $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re:	fclean all

.PHONY:	all clean fclean re init re_lib


