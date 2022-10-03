#===============================================================================
# Variables ====================================================================
#===============================================================================
NAME		:=	fractol
MINILIBX	?=	$(MINILIBX_DIR)libmlx_Linux.a

# Directories ------------------------------------------------------------------
MINILIBX_DIR:=	lib/minilibx-linux/
SRC_DIR		:=	src/
OBJ_DIR		:=	build/

# Files ------------------------------------------------------------------------
FILES	:=	main.c
OBJ		:=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

# Compiler ---------------------------------------------------------------------
CC			:=	gcc
DEBUG		:=	yes
ifeq ($(DEBUG), yes)
FLAG		:=	-g -W
else
FLAG		:=	-Wall -Wextra -Werror
endif

# Colors -----------------------------------------------------------------------
DELETE		:= "\033[33m"
CREATE		:= "\033[32m"
SUCCESS		:= "\033[30;42m"
RESET_COLOR	:= "\033[0m"

#===============================================================================
# Rules ========================================================================
#===============================================================================
all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	@$(CC) $(OBJ) -o $@ $(MINILIBX) -lXext -lX11 -lm
	@echo $(SUCCESS) "FRACTOL >>> $(NAME) created" $(RESET_COLOR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CREATE) "FRACTOL >>> $@ created" $(RESET_COLOR)

$(MINILIBX):
	@make --no-print-directory -C $(MINILIBX_DIR)

# Clean up ---------------------------------------------------------------------
clean:
	@make --no-print-directory clean -C $(MINILIBX_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo $(DELETE) "FRACTOL >>> $(NAME) deleted" $(RESET_COLOR)
	@echo $(DELETE) "FRACTOL >>> $(OBJ_DIR) deleted" $(RESET_COLOR)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: clean, all, fclean, re
