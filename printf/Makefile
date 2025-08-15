SRCS := ft_printf.c ft_putnbr_base.c ft_putnbr_fd.c
NAME := libftprintf.a
OBJ := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $(<:%.c=%.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
