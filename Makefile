NAME := minishell
INCLUDE := -I includes
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

RM = rm -f
RM_DIR = rm -rf

LIB_DIR := Libft
LDFLAGS := -L$(LIB_DIR) -lft
LIBFT := $(LIB_DIR)/libft.a

PARSER_DIR := src/parser
UTILS_DIR := src/utils
SRC_DIR := src/parser src/utils
SRCS := $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ_DIR := obj/
OBJS := $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# COLORS
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
BLUE   := \033[34m
RESET  := \033[0m

vpath %.c $(SRC_DIR)

.SILENT:
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling Libft...$(RESET)"
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@echo "$(GREEN)Libft compiled!$(RESET)"
	@echo "$(BLUE)Compiling minishell...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) -lreadline -o $(NAME)
	@echo "$(GREEN)Minishell compiled!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@$(RM) $(OBJS)
	@$(RM_DIR) $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory
	@echo "$(GREEN)clean done!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory
	@echo "$(GREEN)fclean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
