#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: push_swap																#\
#########################################################################################

NAME = $(BIN_DIR)push_swap
BONUS = $(BIN_DIR)checker

CC	= cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = ./lib/libft/
FT_PRINTF_PATH = ./lib/ft_printf/
LIBFT = $(LIBFT_PATH)bin/libft.a
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
			sort					\
			sort_turk				\
			sort_turk_exec_moves	\
			sort_turk_calc_moves	\
			sort_chunks				\
			sort_precomp			\
			stack_arithmetic		\
			stack					\
			stack_info				\
			stack_operations		\
			stack_rotate			\
			stack_pushswap			\
			stack_exec_moves

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

########################################################################################\
Checker sources & objects
########################################################################################

B_FILES	=	checker_bonus			\
			error					\
			input					\
			input_assert			\
			sort					\
			sort_turk				\
			sort_turk_exec_moves	\
			sort_turk_calc_moves	\
			sort_chunks				\
			sort_precomp			\
			stack_arithmetic		\
			stack					\
			stack_info				\
			stack_operations		\
			stack_rotate_bonus		\
			stack_pushswap_bonus	\
			stack_exec_moves

B_SRCS	=	$(addsuffix .c, $(B_FILES))
B_OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_FILES)))

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

all: libft ft_printf $(NAME) bonus

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

bonus: libft ft_printf $(BONUS)

$(BONUS): $(B_OBJS)
	@$(CC) $(B_OBJS) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "\n$(G)Checker bonus compilation finished!$(DEF_COLOR)-> $(BONUS)\n"

clean: clean_libs
	@$(RM) $(OBJS) $(B_OBJS)
	@echo "$(R)[$(NAME)] All $(OBJ_DIR)*.o files removed$(DEF_COLOR)\n"

fclean: clean fclean_libs
	@$(RM) $(NAME) $(BONUS)
	@echo "$(R)Push swap binaries removed$(DEF_COLOR)\n"

clean_libs:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)

fclean_libs:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)

re: fclean all

norminette:
	norminette $(SRC_DIR)

.PHONY: all clean fclean re norminette