NAME := minishell
INCLUDE := -I includes
CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM = rm -f
RM_DIR = rm -rf

LIB_DIR := Libft
LDFLAGS := -L$(LIB_DIR) -lft
LIBFT := $(LIB_DIR)/libft.a

PARSER_DIR := src/parser
PARSER_SRC := $(wildcard $(PARSER_DIR)/*.c)
OBJ_DIR := obj/
OBJS := $(addprefix $(OBJ_DIR), $(notdir $(PARSER_SRC:.c=.o)))

.SILENT:
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(PARSER_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "Compiling Libft..."
	$(MAKE) -C $(LIB_DIR)
	@echo "Compiling minishell..."
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) -lreadline -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM_DIR) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "fclean done"

re: fclean all

.PHONY: all clean fclean re
