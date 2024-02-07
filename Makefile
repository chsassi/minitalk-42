NAME = minitalk

CC = cc
HEADER = ./libft.plus/headers
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADER)
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

LIBFT_DIR = ./libft.plus

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =   ./src/main.c \
		./src/client.c \
		./src/server.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(YELLOW)	MINITALK COMPILED! 📲✅$(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all