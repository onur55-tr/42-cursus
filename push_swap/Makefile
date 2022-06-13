# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+      #
#    By: odursun <odursun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:02:20 by odursun           #+#    #+#              #
#    Updated: 2022/06/02 19:40:51 by odursun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

RM = rm -rf

SRC_DIR = Source/
OBJ_DIR = Object/

SRC_FILES = alignment.c args_check.c error.c indexing.c list2.c \
alignment_together.c args_list.c ft_atoi.c list.c main.c count.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)

BNS_FILES = checker.c alignment.c alignment_together.c error.c count.c ft_atoi.c args_check.c

SRC_B = $(addprefix $(SRC_DIR), $(BNS_FILES))
OBJ_B = $(addprefix $(OBJ_DIR), $(OBJ_B_FILES))

OBJ_B_FILES = $(BNS_FILES:.c=.o)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

LIBFT = Libft/libft.a

FT_PRINTF = Printf/libftprintf.a

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
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
		@$(PRINTF) "➤ $(NAME)\033[0;92m is up to date!\033[0;39m\n"
		@if [ ! -f $(NAME) ]; then \
			$(PRINTF) "➤ $(RED)no create $(NAME)$(LAST)\n"; \
		fi

compile:
		@if [ ! -d "libft" ]; then \
			git clone https://github.com/onur55-tr/Libft; \
			make all -C libft; \
		fi
		@if [ ! -d "printf" ]; then \
			git clone https://github.com/onur55-tr/Printf.git; \
			make all -C printf; \
		fi
		@if [ ! -d "gnl" ]; then \
			git clone https://github.com/onur55-tr/Gnl.git; \
		fi

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(YELLOW)Compiling [$@]...$(RESET)"
		@$(CC) $(CFLAGS) -I Include/ -o $@ -c $<
		@printf "$(UP)$(CUT)"
		@echo "$(GREEN)Finished [$@]$(RESET)"
		@printf "$(UP)$(CUT)"

bonus: compile $(OBJ_B)
		$(CC) $(CFLAGS) $(OBJ_B) $(GNL) $(LIBFT) $(FT_PRINTF) -o checker
		@$(PRINTF) "➤ checker\033[0;92m is up to date!\033[0;39m\n"

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
		@$(RM) $(OBJ_DIR)
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
