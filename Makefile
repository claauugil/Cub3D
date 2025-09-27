SRCS= main.c

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
PINK = \033[38;2;245;166;221m
RESET = \033[0m
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES =

HEADER = "\
$(PINK)▞▀▖▌ ▌▛▀▖ ▞▀▖▛▀▖\n\
▌  ▌ ▌▙▄▘  ▄▘▌ ▌\n\
▌ ▖▌ ▌▌ ▌ ▖ ▌▌ ▌\n\
▝▀ ▝▀ ▀▀  ▝▀ ▀▀$(RESET)\n"

all: $(NAME)

$(NAME): $(OBJS)
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME) > /dev/null 2>&1
	@printf $(HEADER)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "cleaned"

fclean:
	@rm -f $(OBJS) $(NAME)
	@echo "fully clean"

re: fclean all

.PHONY: clean fclean all re
