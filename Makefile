#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: push_swap																#\
#########################################################################################

NAME = $(BIN_DIR)push_swap.out

CC	= cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./lib/libft/bin/
FT_PRINTF_PATH = ./lib/ft_printf/
LIBFT = $(LIBFT_PATH)libft.a
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	./lib/
BIN_DIR = 	./bin/
OBJ_DIR =	$(BIN_DIR)obj/
SRC_DIR	=	./src/

########################################################################################\
Sources & objects
########################################################################################

FILES	=	main					\
			error					\
			input					\
			input_assert			\
			stack_arithmetic		\
			stack					\
			stack_operations		\
			stack_rotate			\
			stack_pushswap

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

########################################################################################\
Colors
########################################################################################

DEF_COLOR = \033[0;39m
CUT = 		\033[K
R = 		\033[31;1m
G = 		\033[32;1m
Y = 		\033[33;1m
B = 		\033[34;1m
P = 		\033[35;1m
GR = 		\033[30;1m
END = 		\033[0m

########################################################################################\
Rules
########################################################################################

all: libft ft_printf $(NAME)

libft: $(LIBFT)

ft_printf: $(FT_PRINTF)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "\n$(G)Push swap compilation finished!$(DEF_COLOR)-> $(NAME)\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(R)[$(NAME)] All $(OBJ_DIR)*.o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Push swap binary removed$(DEF_COLOR)\n"

clean_libs:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)

fclean_libs:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)

re: fclean all

norminette:
	norminette $(SRC_DIR)

.PHONY: all bonus clean fclean re server client norminette