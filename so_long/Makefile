NAME = so_long

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX = Minilibx/libmlx.a

LMLX = -framework OpenGL -framework AppKit $(MLX)

SRC_DIR = sources

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

FT_PRINTF = printf/libftprintf.a

LIBFT = libft/libft.a

MAPS = maps/example.ber

all: $(NAME)

$(NAME): compile $(OBJ)
		@$(PRINTF) "➤ \033[0;92marşivleme işlemi başlatılıyor...\033[0;39m\n"
		@$(CC) $(CFLAGS) $(SRC_DIR)/*.c $(LMLX) $(FT_PRINTF) $(LIBFT) -ggdb -o $(NAME)
		@$(PRINTF) "➤ $(NAME)\033[0;92m is up to date!\033[0;39m\n"
		@if [ ! -f "so_long" ]; then \
			$(PRINTF) "➤ no create so_long\033[0;39m"; \
		fi

compile:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/onur55-tr/Libft; \
		make all -C libft/; \
	fi
	@if [ ! -d "printf" ]; then \
		git clone https://github.com/onur55-tr/Printf.git; \
		make all -C printf/; \
	fi
	@if [ ! -d "Minilibx" ]; then \
		git clone https://github.com/onur55-tr/Minilibx.git; \
		make all -C Minilibx/; \
	fi

play: all
	@for map in $(MAPS) ; do \
		$(PRINTF) "➤ Command: ./$(NAME) $(MAPS)\033[0;39m\n" ; \
		./$(NAME) $(MAPS) ; \
	done

norminette: compile
	@if [ -d "libft" ]; then \
		norminette libft/; \
	fi
	@if [ -d "printf" ]; then \
		norminette printf/; \
	fi
	@if [ -d "sources" ]; then \
		norminette sources/ include/; \
	fi

clean:
		@if [ -d "Minilibx" ]; then \
			make clean -C Minilibx; \
			$(PRINTF) "Minilibx nesne dosyaları kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -d "libft" ]; then \
			make clean -C libft; \
			$(PRINTF) "Libft'nin nesne dosyaları kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -d "printf" ]; then \
			make clean -C printf; \
			$(PRINTF) "Printf'nin nesne dosyaları kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -d "so_long.dSYM" ]; then \
			$(RM) so_long.dSYM; \
			$(PRINTF) "The Debug Symbols klasörü kaldırıldı\033[0;39m\n"; \
		fi 
		@$(RM) $(OBJ)
		@$(PRINTF) "Sources nesne dosyaları kaldırıldı...\033[0;39m\n"

fclean: clean
		@if [ -f $(MLX) ]; then \
			$(RM) $(MLX); \
			$(PRINTF) "$(MLX) dosyası kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -f $(FT_PRINTF) ]; then \
			$(RM) $(FT_PRINTF); \
			$(PRINTF) "$(FT_PRINTF) dosyası kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -f $(LIBFT) ]; then \
			$(RM) $(LIBFT); \
			$(PRINTF) "$(LIBFT) dosyası kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -f "so_long" ]; then \
			$(RM) $(NAME); \
			$(PRINTF) "So_long exec kaldırıldı...\n"; \
		fi
		@if [ -d "Libft" ]; then \
			$(RM) Libft; \
			$(PRINTF) "Libft klasörü kaldırıldı...\n"; \
		fi
		@if [ -d "printf" ]; then \
			$(RM) Printf; \
			$(PRINTF) "Printf klasörü kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -d "Minilibx" ]; then \
			$(RM) Minilibx; \
			$(PRINTF) "Minilibx klasörü kaldırıldı...\n"; \
		fi

re: fclean all

.PHONY: all clean fclean re compile test play
