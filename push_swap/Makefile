# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odursun <odursun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:02:20 by odursun           #+#    #+#              #
#    Updated: 2022/04/03 14:33:23 by odursun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_DIR = Source/*.c

SRC = $(wildcard $(SRC_DIR)) 

OBJ = $(SRC:.c=.o)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

LIBFT = libft/libft.a

FT_PRINTF = printf/libftprintf.a

GNL = $(wildcard Gnl/*.c)

all: $(NAME)

$(NAME): compile $(OBJ)
		@$(PRINTF) "➤ \033[0;92m derleme işlemi başlatılıyor...\033[0;39m\n"
		@$(CC) $(CFLAGS) $(SRC_DIR) $(LIBFT) $(FT_PRINTF) -o $(NAME)
		@$(PRINTF) "➤ $(NAME)\033[0;92m is up to date!\033[0;39m\n"
		@if [ ! -f $(NAME) ]; then \
			$(PRINTF) "➤ no create $(NAME)\033[0;39m"; \
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
		@if [ ! -d "gnl" ]; then \
			git clone https://github.com/onur55-tr/Gnl.git; \
		fi
bonus: $(NAME) $(OBJ)
		$(CC) $(CFLAGS) $(filter-out Source/main.o ,$(OBJ)) $(GNL) $(LIBFT) $(FT_PRINTF) checker.c -o checker

norminette: compile
			@if [ -d "Libft" ]; then \
				norminette libft/; \
			fi
			@if [ -d "Printf" ]; then \
				norminette Printf/; \
			fi
			@if [ -d "Source" ]; then \
				norminette Source/*.c Include/*.h; \
			fi

clean:
		@if [ -d "libft" ]; then \
			make clean -C libft; \
			$(PRINTF) "Libft'nin nesne dosyaları kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -d "printf" ]; then \
			make clean -C printf; \
			$(PRINTF) "Printf'nin nesne dosyaları kaldırıldı...\033[0;39m\n"; \
		fi
		@$(RM) $(OBJ)
		@$(PRINTF) "Source'nin nesne dosyaları kaldırıldı...\033[0;39m\n"
fclean: clean
		@if [ -d $(Gnl) ]; then \
			$(RM) Gnl; \
			$(PRINTF) "Gnl dosyası kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			$(PRINTF) "$(NAME) exec kaldırıldı...\n"; \
		fi
		@if [ -d "Libft" ]; then \
			$(RM) Libft; \
			$(PRINTF) "Libft klasörü kaldırıldı...\n"; \
		fi
		@if [ -d "printf" ]; then \
			$(RM) Printf; \
			$(PRINTF) "Printf klasörü kaldırıldı...\033[0;39m\n"; \
		fi
		@if [ -f "checker" ]; then \
			$(RM) checker; \
			$(PRINTF) "checker exec kaldırıldı...\033[0;39m\n"; \
		fi

re: fclean all

.PHONY: all clean fclean re compile