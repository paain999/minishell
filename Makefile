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
PARSER_SRC := $(wildcard $(PARSER_DIR)/*.c)
OBJ_DIR := obj/
OBJS := $(addprefix $(OBJ_DIR), $(notdir $(PARSER_SRC:.c=.o)))

# COLORS
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
BLUE   := \033[34m
RESET  := \033[0m

.SILENT:
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(PARSER_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling Libft...$(RESET)"
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@echo "$(GREEN)Libft compiled!$(RESET)"
	@echo "$(BLUE)Compiling minishell...$(RESET)"
	@sleep 1
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) -lreadline -o $(NAME)
	@echo "$(GREEN)Minishell compiled!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@sleep 1
	@echo "$(RED)Removing object files...$(RESET)"
	@sleep 0.1
	@$(RM) $(OBJS)
	@echo "$(RED)Removing object directory...$(RESET)"
	@sleep 0.1
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(RED)Cleaning Libft...$(RESET)"
	@sleep 0.1
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory
	@echo "$(GREEN)clean done!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory
	@echo "$(GREEN)fclean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
