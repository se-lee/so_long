NAME	= so_long
HEADER	= so_long.h

INC		= include
SRC_DIR	= srcs
OBJ_DIR	= objs
SRC		=	main.c\
			map_check.c\
			map_read.c\
			map_render.c\
			player_render.c\
			init_game.c\
			init_img.c\
			get_next_line.c\
			key_event.c\
			move_player.c\
			exit_game.c\

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIBFT	= libft
LIBFT_FILE = $(LIBFT)/libft.a
RM		= rm -rf

CC		= cc
CFLAGS	= -g -fsanitize=address #-D DEBUG #-Wall -Wextra -Werror
CLIB	= -I ./minilibx_mms_20200219 -L ./minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit
#CLIB	= -I ./minilibx_mms_20210621 -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

#--
# debug(printf, "[pb_count(merge)]: %d \n", count.pb_count);

#$(NAME): $(OBJ)
#	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#--

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
