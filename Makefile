NAME	= so_long
HEADER	= so_long.h

INC		= include
SRC_DIR	= srcs
OBJ_DIR	= objs
SRC		=	main.c\
			collect.c\
			collision.c\
			display.c\
			exit.c\
			free.c\
			get_next_line.c\
			init_game.c\
			init_img.c\
			key_event.c\
			map_check.c\
			map_compo.c\
			map_read.c\
			player_move.c\
			player_position.c\

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIBFT	= libft
LIBFT_FILE = $(LIBFT)/libft.a
RM		= rm -rf

CC		= cc
CFLAGS	= -g -D DEBUG -Wall -Wextra -Werror
CLIB	= -I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit

all:	init $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(LIBFT)/libft.h include/so_long.h
	$(CC) $(CFLAGS) -c $< -Ilibft -o $@

$(NAME):	$(OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -I $(INC) $(LIBFT_FILE) -o $(NAME)

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

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re init re_lib
