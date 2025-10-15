SRCS= src/main.c \
	  src/parsing/validate_mapfile.c \
	  src/utils.c \
	  src/parsing/headers/parsing.c \
	  src/parsing/headers/parse_headers.c \
	  src/parsing/headers/check_textures.c \
	  src/parsing/headers/parse_header_utils.c \
	  src/parsing/map/handle_map.c \
	  gnl/get_next_line.c \

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
PINK = \033[38;2;245;166;221m
RESET = \033[0m
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) 

HEADER = "\
\n\
$(PINK)▞▀▖▌ ▌▛▀▖ ▞▀▖▛▀▖\n\
▌  ▌ ▌▙▄▘  ▄▘▌ ▌\n\
▌ ▖▌ ▌▌ ▌ ▖ ▌▌ ▌\n\
▝▀ ▝▀ ▀▀  ▝▀ ▀▀$(RESET)\n\
\n"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cd $(MLX_DIR) && $(MAKE) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME) 
	printf $(HEADER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	cd $(MLX_DIR) && $(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all