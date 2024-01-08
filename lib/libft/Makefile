#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: Libft																	#\
#########################################################################################

NAME = $(BIN_DIR)libft.a

CC	= cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	includes/
BIN_DIR =	bin/
SRC_DIR	=	src/

ARRAY_DIR =		array/
CTYPE_DIR =		ctype/
LIST_DIR =		list/
MATH_DIR =		math/
STDIO_DIR =		stdio/
STDLIB_DIR =	stdlib/
STRING_DIR =	string/
STRMTRX_DIR =	strsmatrix/


########################################################################################\
Sources & objects for Libft
########################################################################################

ARRAY_FILES =	ft_arrset

CTYPE_FILES	=	ft_isalnum	\
				ft_isalpha	\
				ft_isascii	\
				ft_isblank	\
				ft_isdigit	\
				ft_islower	\
				ft_isprint	\
				ft_isspace	\
				ft_isupper	\
				ft_tolower	\
				ft_toupper	

LIST_FILES =	ft_lstadd_back_bonus	\
				ft_lstadd_front_bonus	\
				ft_lstclear_bonus		\
				ft_lstdelone_bonus		\
				ft_lstiter_bonus		\
				ft_lstlast_bonus		\
				ft_lstmap_bonus			\
				ft_lstnew_bonus			\
				ft_lstsize_bonus		\
				ft_lst_exists			\
				ft_lst_remove			\
				ft_lst_remove_at		\
				ft_lst_removeall		\
				ft_lst_dup				\


MATH_FILES =	ft_maxmin	\
				ft_pow

STDIO_FILES =	ft_putchar_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\
				ft_putnbrlen_fd	\
				ft_putnbrlen_hex \
				ft_putstr_fd	\
				ft_putstrlen_fd	\
				ft_putnbr_base

STDLIB_FILES =	frees 		\
				ft_calloc	\
				ft_atoi		\
				ft_atol		\
				ft_itoa		

STRING_FILES =	ft_memcmp	\
				ft_strcmp	\
				ft_bzero	\
				ft_memccpy	\
				ft_memcpy	\
				ft_memmove	\
				ft_memset	\
				ft_split	\
				ft_strcat	\
				ft_strcpy	\
				ft_strdup	\
				ft_strlcat	\
				ft_strlcpy	\
				ft_strncat	\
				ft_strncpy	\
				ft_strtrim	\
				ft_memchr 	\
				ft_memrchr 	\
				ft_strchr 	\
				ft_strjoin 	\
				ft_strncmp 	\
				ft_strnstr 	\
				ft_strrchr 	\
				ft_strstr 	\
				ft_substr 	\
				ft_striteri	\
				ft_strlen 	\
				ft_strmapi 	\

STRSMTRX_FILES =	ft_strs_add_line	\
					ft_strs_cols		\
					ft_strs_rows		\
					ft_strs_clear		\
					ft_strs_colcmp		\
					ft_strs_rowcmp		\
					ft_strschr			\
					ft_strscpy			\
					ft_strs_free		\
					ft_strsdup


FILES	=	$(addprefix $(CTYPE_DIR), $(CTYPE_FILES))		\
			$(addprefix $(ARRAY_DIR), $(ARRAY_FILES))		\
			$(addprefix $(LIST_DIR), $(LIST_FILES))			\
			$(addprefix $(MATH_DIR), $(MATH_FILES))			\
			$(addprefix $(STDIO_DIR), $(STDIO_FILES))		\
			$(addprefix $(STDLIB_DIR), $(STDLIB_FILES))		\
			$(addprefix $(STRING_DIR), $(STRING_FILES))		\
			$(addprefix $(STRMTRX_DIR), $(STRSMTRX_FILES))
		
SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FILES)))

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

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(G)Library compiled!$(DEF_COLOR)-> $@\n"

$(BIN_DIR)%.o:$(SRC_DIR)%.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@

bonus: $(OBJS) $(BOBJS)
	@$(AR) $(NAME) $(OBJS) $(BOBJS)
	@echo "\n$(G)Library with bonus compiled!$(DEF_COLOR)-> $(NAME)\n"

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all