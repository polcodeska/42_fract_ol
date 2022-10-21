#===============================================================================
# Variables ====================================================================
#===============================================================================
NAME		:=	fractol
MINILIBX	?=	$(MINILIBX_DIR)libmlx_Linux.a
LIBFT   ?=  $(LIBFT_DIR)libft.a

# Directories ------------------------------------------------------------------
MINILIBX_DIR:=	lib/minilibx-linux/
LIBFT_DIR   :=  lib/libft/
SRC_DIR		:=	src/
OBJ_DIR		:=	build/

# Files ------------------------------------------------------------------------
FILES	:=	main.c ft_draw_1.c ft_draw_2.c ft_event.c
OBJ		:=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

# Compiler ---------------------------------------------------------------------
CC			:=	gcc
DEBUG		:=	no
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

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	@$(CC) $(OBJ) -o $@ $(MINILIBX) $(LIBFT) -lXext -lX11
	@echo $(SUCCESS) "FRACTOL [create] : $(NAME)" $(RESET_COLOR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CREATE) "FRACTOL [create] : $@" $(RESET_COLOR)

$(MINILIBX):
	@make --no-print-directory -C $(MINILIBX_DIR)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

# Clean up ---------------------------------------------------------------------
clean:
	@make --no-print-directory clean -C $(MINILIBX_DIR)
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@rm -rfd $(OBJ_DIR)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo $(DELETE) "FRACTOL [delete] : $(NAME)" $(RESET_COLOR)
	@echo $(DELETE) "FRACTOL [delete] : $(OBJ_DIR)*" $(RESET_COLOR)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: clean, all, fclean, re
