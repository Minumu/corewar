LIB     = ../libft/
NAME    = asm
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc
BYTE = generate_bytecode
VALID = validation
SUPPORT = support_functions
PARSING = parsing

SRCS = main.c \
	   $(BYTE)/generate_bytecode.c \
	   $(BYTE)/get_coding_byte.c \
	   $(BYTE)/get_indir_tdir.c \
	   $(BYTE)/get_label_bytecode.c \
	   $(BYTE)/get_magic.c \
	   $(BYTE)/get_prog_size.c \
	   $(BYTE)/is_dir_indir_reg.c \
	   $(BYTE)/write_code_to_file.c \
	   $(PARSING)/parse_args.c \
	   $(PARSING)/parse_label.c \
	   $(PARSING)/parse_main.c \
	   $(PARSING)/parse_name_comment.c \
	   $(SUPPORT)/bonus_funcs.c \
	   $(SUPPORT)/clean_trash.c \
	   $(SUPPORT)/ft_support_func.c \
	   $(SUPPORT)/init_struct.c \
	   $(SUPPORT)/support_functions_two.c \
	   $(VALID)/check_conformity.c \
	   $(VALID)/check_filename.c \
	   $(VALID)/valid_name_comment_min.c \
	   $(VALID)/valid_name_comment.c \
	   $(VALID)/validate_args.c \
	   $(VALID)/validate_commands.c \
	   $(VALID)/validate_content.c \
	   $(VALID)/validate_label.c \
	   $(VALID)/validation.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@printf "libft.a:\n"
	@make -C $(LIB)
	@printf "\x1b[33m[libft.a created]\x1b[0m\n"
	@$(CC)  $(SRCS) $(LIB)libft.a -o $(NAME)
	@printf "\x1b[33m[%s created]\x1b[0m\n" $(NAME)

.c.o:
		@printf "\x1b[36m[+]\x1b[0m %s\n" $<
		@$(CC) $(CFLAGS)  -c $<  -o $@

clean:
		@printf "\x1b[31mDelete objects:\x1b[0m\n"
		@rm -rf $(OBJS)
		@make -C $(LIB) clean

fclean: clean
		@printf "\x1b[31mDelete %s && libft/libft.a:\x1b[0m\n" $(NAME)
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all
