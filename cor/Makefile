LIB     = ../libft/
NAME    = corewar
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc
MAP = init_map
VALID = validation
SUPPORT = support_functions
PARSING = parsing
FIGHT = processing_fight
VM_FUNC = vm_functions
NC = ncurses

SRCS = main.c \
	   $(MAP)/create_arena.c \
	   $(MAP)/create_cursor.c \
	   $(PARSING)/check_champ.c \
	   $(PARSING)/parse_args.c \
	   $(PARSING)/parse_champ.c \
	   $(PARSING)/parse_flags.c \
	   $(FIGHT)/dump_corewar.c \
	   $(FIGHT)/get_args_from_map.c \
	   $(FIGHT)/get_reg.c \
	   $(FIGHT)/declare_winner.c \
	   $(FIGHT)/kill_cursor.c \
	   $(FIGHT)/init_great_war.c \
	   $(FIGHT)/manage_functions.c \
	   $(FIGHT)/move_cursor.c \
	   $(SUPPORT)/ft_support_func.c \
	   $(SUPPORT)/init_struct.c \
	   $(SUPPORT)/work_with_binary.c \
	   $(VALID)/validate_commands_first.c \
	   $(VALID)/validate_commands_main.c \
	   $(VALID)/validate_commands_second.c \
	   $(VM_FUNC)/lldi_lld_lfork_fork.c \
	   $(VM_FUNC)/or_and_sub_add.c \
	   $(VM_FUNC)/st_ld_live.c \
	   $(VM_FUNC)/sti_ldi_zjump_xor.c \
	   $(NC)/ncurses.c \
	   $(NC)/init_window.c \
	   $(NC)/colors.c \
	   $(NC)/end_game.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "libft.a:\n"
	@make -C $(LIB)
	@printf "\x1b[33m[libft.a created]\x1b[0m\n"
	@$(CC) -lncurses $(SRCS) $(LIB)libft.a -o $(NAME)
	@printf "\x1b[33m[%s created]\x1b[0m\n" $(NAME)

.c.o:
		@printf "\x1b[36m[+]\x1b[0m %s\n" $<
		@$(CC) $(CFLAGS) -c $<  -o $@

clean:
		@printf "\x1b[31mDelete objects:\x1b[0m\n"
		@rm -rf $(OBJS)
		@make -C $(LIB) clean

fclean: clean
		@printf "\x1b[31mDelete %s && libft/libft.a:\x1b[0m\n" $(NAME)
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all
