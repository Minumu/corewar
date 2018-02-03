#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:47:54 by tshevchu          #+#    #+#              #
#    Updated: 2017/07/14 14:28:54 by tshevchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

HEADERS = include

FLAGS = -Wall -Wextra -Werror

SRC_LIB = libft

SRC_GNL = get_next_line

SRC_PRINTF = ft_printf

OBJ_GNL = get_next_line.o

OBJ_PRINTF = ft_printf.o check_struct.o record_struct.o print_s_c.o syntax_s.o print_wc_ws.o\
additional_print_wc_ws.o additional_wchar.o print_d_i_o_x.o syntax_d_i.o syntax_o_x.o\
additional_functions_number.o handle_size.o lib_functions.o lib_functions2.o additional_u.o\
syntax_u.o

OBJ_LIB = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_strrev.o ft_fprime.o ft_list_clear.o

ALL_OBJ = $(OBJ_LIB) $(OBJ_GNL) $(OBJ_PRINTF)

all: $(NAME)

$(NAME): $(ALL_OBJ)
	@ar rc $(NAME) $(ALL_OBJ)
	@echo "\033[0;32m>>>LIBFT IS HERE<<<"

$(OBJ_LIB): %.o: $(SRC_LIB)/%.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

$(OBJ_GNL): %.o: $(SRC_GNL)/%.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

$(OBJ_PRINTF): %.o: $(SRC_PRINTF)/%.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

clean:
	@rm -f $(ALL_OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;34m>>>CLEAN LIBFT<<<"

re: fclean all