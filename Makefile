LIB     = libft/
NAME    = corewar
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = ft_support_func.c \
         init_struct.c \
         main.c \
         parsing.c \
         parse_champ.c \
         check_champ.c \
         decode_binary.c \
         create_arena.c \
         init_great_war.c \
         create_cursor.c \
         get_index.c \
         validate_commands.c \
         manage_functions.c \
         ncurses.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@printf "[CC] libft.a start:\n"
		@make -C $(LIB)
		@printf "[CC] libft.a finished successfull!\n"
		@$(CC) $(SRCS) -lncurses $(LIB)libft.a -o $(NAME)
		@printf "[CC] %s\n" $(NAME)

.c.o:
		@printf "[CC] %s\r" $<
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@printf "[RM] objects\n"
		@rm -rf $(OBJS)
			@make -C $(LIB) clean

fclean: clean
		@printf "[RM] %s libft/libft.a\n" $(NAME)
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all
