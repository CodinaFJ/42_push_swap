#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: ft_printf																#\
#########################################################################################

NAME = libftprintf.a

CC	= cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ../libft/bin/
LIBFT = $(LIBFT_PATH)libft.a
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	.
SRC_DIR	=	.

########################################################################################\
Sources & objects
########################################################################################

FILES	=	ft_printf		\
			printf_char		\
			printf_str		\
			printf_int		\
			printf_hex		\
			printf_ptr		\

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addsuffix .o, $(FILES))
			
########################################################################################\
Bonus sources and objects
########################################################################################

BFILES	=	

BSRCS	=	$(addsuffix .c, $(BFILES))
BOBJS	=	$(addsuffix .o, $(BFILES))

########################################################################################\
Colors
########################################################################################

DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################################################################################\
Rules
########################################################################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS) $(LIBFT)
	@echo "\n$(G)Ft_printf library compiled!$(DEF_COLOR)-> $(NAME)\n"

%.o:%.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all bonus clean fclean re