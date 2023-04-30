NAME = megaphone

SRC = megaphone.cpp

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling $(NAME) 🚀"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32mCompiled ✅\033[0;37m"

clean:
	@echo "\033[0;31mCleaning 🧹"
	@rm -rf $(NAME)

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"

re: fclean all

.PHONY: all clean fclean re
