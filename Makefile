HEADER	= so_long.h
SRC		= srcs
INC		= include
BIN		= objs
SRCS	=	map_read.c\
			map_check.c\
			map_draw.c\
			map_coordinates.c\
			move_key.c\
			get_next_line.c\
			main.c\

OBJS		= $(addprefix $(BIN)/, $(SRCS:%.c=%.o))
NAME	= so_long
LIBFT	= libft
LIBFT_FILE = $(LIBFT)/libft.a
CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
CLIB	= -I ./minilibx_mms_20210621 -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

all:	init $(NAME)

$(BIN)/%.o:	$(SRC)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CLFAGS) $(CLIB) $($(SRC)/$(SRCS)) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

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
