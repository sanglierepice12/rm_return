# Color
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -lreadline

# Source and objet directories
SRC_DIR = ./src
OBJ_DIR = ./obj
DEP_DIR = ./dep

# Source files
SRCS =	main.c 						\
		utils/lk_lst.c					\
		utils/read_doc.c				\
		utils/set.c
# Objet files
OBJS =	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Executable Name
NAME = rm_return

# Target
.SILENT: all clean fclean re

all: $(NAME)
	@echo "$(GREEN)Compilation completed successfully!$(NC)"

-include $(DEPS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Linking completed!$(NC)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(OBJ_DIR)/utils $(DEP_DIR)/utils
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@
	@echo "$(GREEN)Compilation of $< completed!$(NC)"

clean:
	rm -fr $(OBJ_DIR) $(DEP_DIR)
	@echo "$(RED)Cleanup completed!$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Deletion of the executable completed!$(NC)"

re: fclean all

.PHONY: all clean fclean re
