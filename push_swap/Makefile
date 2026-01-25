NAME = push_swap

SRCS = push_swap.c add_index.c fill_stack.c push.c reverse_rotate.c rotate.c sort_2_3.c sort_4_5.c swap.c utils.c validate_data.c radix.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
		rm -f $(OBJS)
		$(MAKE) clean -C libft

fclean: clean
		rm -f $(NAME)
		$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re