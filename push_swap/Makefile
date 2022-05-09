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

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

RM = rm -rf

SRC_DIR = Source/*c

SRC = $(wildcard $(SRC_DIR)) 

OBJ = $(SRC:.c=.o)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

LIBFT = libft/libft.a

FT_PRINTF =printf/libftprintf.a

GNL = $(wildcard Gnl/*.c)

RESET		=	\033[0m
BLUE		=	\033[34m
RED		=	\033[31m
UP		=	\033[A
CUT		=	\033[K
IGREEN		=	\033[0;92m
LAST		= \033[0;39m

all: | compile

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(SRC_DIR) $(LIBFT) $(FT_PRINTF) -o $(NAME)
		@$(PRINTF) "➤ $(NAME)\033[0;92m is up to date!\033[0;39m\n"
		@if [ ! -f $(NAME) ]; then \
			$(PRINTF) "➤ $(RED)no create $(NAME)$(LAST)\n"; \
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
  			$(PRINTF) "$(IGREEN)Started removing Libft in object files...$(LAST)\n"; \
  			$(PRINTF) "$(UP)$(CUT)"; \
			make clean -C libft; \
			$(PRINTF) "$(RED)Removed Libft in object files$(LAST)\n"; \
		fi
		@if [ -d "printf" ]; then \
			$(PRINTF) "$(IGREEN)Started removing Printf in object files...$(LAST)\n"; \
			$(PRINTF) "$(UP)$(CUT)"; \
			make clean -C printf; \
			$(PRINTF) "$(RED)Removed Printf in object files$(LAST)\n"; \
		fi
		@$(PRINTF) "$(IGREEN)Started removing Source in object files...$(LAST)\n"
		@$(RM) $(OBJ)
		@$(PRINTF) "$(UP)$(CUT)"
	  	@$(PRINTF) "$(RED)Removed Source in object files$(LAST)\n"

fclean: clean
		@if [ -d $(Gnl) ]; then \
			$(RM) Gnl; \
			$(PRINTF) "$(BLUE)Removed Get_next_line folder...$(LAST)\n"; \
		fi
		@if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			$(PRINTF) "$(BLUE)$(NAME) Removed executable...$(LAST)\n"; \
		fi
		@if [ -d "Libft" ]; then \
			$(RM) Libft; \
			$(PRINTF) "$(BLUE)Removed Libft folder...$(LAST)\n"; \
		fi
		@if [ -d "printf" ]; then \
			$(RM) Printf; \
			$(PRINTF) "$(BLUE)Removed Printf folder...$(LAST)\n"; \
		fi
		@if [ -f "checker" ]; then \
			$(RM) checker; \
			$(PRINTF) "$(BLUE)Removed checker executable...$(LAST)\n"; \
		fi

re: fclean all

.PHONY: all clean fclean re compile
