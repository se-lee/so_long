NAME			=	so_long
NAME_BONUS		=	so_long_bonus
HEADER			=	so_long.h
HEADER_BONUS	=	so_long_bonus.h

INC				=	include
INC_BONUS		=	include_bonus
SRC_DIR			=	srcs
SRC_BONUS_DIR	=	srcs_bonus
OBJ_DIR			=	objs
OBJ_BONUS_DIR 	=	objs_bonus
SRC				=	main.c\
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

SRC_BONUS		=	main_bonus.c\
					collect_bonus.c\
					collision_bonus.c\
					display_bonus.c\
					display_steps_bonus.c\
					exit_bonus.c\
					free_bonus.c\
					get_next_line_bonus.c\
					init_game_bonus.c\
					init_img_bonus.c\
					key_event_bonus.c\
					map_check_bonus.c\
					map_compo_bonus.c\
					map_read_bonus.c\
					player_move_bonus.c\
					player_position_bonus.c\

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
SRCS_BONUS		=	$(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS))
OBJS_BONUS		=	$(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:%.c=%.o))
LIBFT			=	libft
LIBFT_FILE		=	$(LIBFT)/libft.a
MLX				=	mlx
RM				= 	rm -rf

CC				=	cc
CFLAGS			=	-g -D DEBUG -Wall -Wextra -Werror
CLIB			=	-I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(LIBFT)/libft.h include/so_long.h
	$(CC) $(CFLAGS) -c $< -Ilibft -o $@

$(OBJ_BONUS_DIR)/%.o:	$(SRC_BONUS_DIR)/%.c $(LIBFT)/libft.h include_bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -Ilibft -o $@

$(NAME):	init $(OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -I $(INC) $(LIBFT_FILE) -o $(NAME)

init:
	@ mkdir -p objs
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT) clean
	@ $(RM) objs objs_bonus
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(MLX) clean

re:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) bonus

bonus: $(NAME_BONUS)

init_bonus:
	@ mkdir -p objs_bonus
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

$(NAME_BONUS):	init_bonus $(OBJS_BONUS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS_BONUS) -I $(INC_BONUS) $(LIBFT_FILE) -o $(NAME_BONUS)

.PHONY:	all clean fclean re init re_lib
