NAME = libftprintf.a

SRCS = ft_printf.c \
	process_format.c \
	ft_utoa_hex_ulong.c \
	ft_utoa_hex.c \
	ft_utoa.c \
	handle_types.c \
	handle_pointer.c  \
	ft_itoa.c  \
	ft_putchar_fd.c  \
	ft_putstr_fd.c  \
	ft_strlen.c  \
	test.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(filter-out test.o,$(OBJS))
	@ar rcs $(NAME) $(filter-out test.o,$(OBJS))

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) test

re: fclean all

test: $(NAME) test.o
	$(CC) $(CFLAGS) test.o -L. -lftprintf -o test
	./test

.PHONY: all clean fclean re test
