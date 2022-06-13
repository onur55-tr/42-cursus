SERVER			=	server
SERVER_SRC		=	./Sources/server.c

CLIENT			=	client
CLIENT_SRC		=	./Sources/client.c 

UTILS_SRC		=	./Sources/utils.c 

CC				=	@gcc
RM 				=	@rm -f
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	@echo "\x1B[38;2;216;195;151mPreparing for $(SERVER)...\033[0m"
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
	@echo "\033[0;31m$(SERVER) created!\033[0m"

$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "\x1B[38;2;216;195;151mPreparing for $(CLIENT)...\033[0m"
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)
	@echo "\033[0;31m$(CLIENT) created!\033[0m"

fclean :
	$(RM) $(SERVER) $(CLIENT)
	@echo "\033[0;31m$(SERVER) and $(CLIENT) deleted.\033[0m"

re : fclean all

.PHONY: all fclean re


