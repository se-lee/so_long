NAME	= a.out

SRCS	= first_practice.c\

OBJ		= $(SRCS:%.c=%.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CLIB	= -I ./minilibx_mms_20210621 first_practice.c -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CLFAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all




