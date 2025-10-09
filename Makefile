SRCS= src/main.c \
	  src/validate_mapfile.c \
	  src/utils.c \
	  src/parsing.c \
	  src/parse_headers.c \

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
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME) > /dev/null 2>&1
	@printf $(HEADER)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@cd $(MLX_DIR) && $(MAKE) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all