SRCS := $(wildcard ft_*.c)
NAME := libft.a
OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	cc -Wall -Wextra -Werror -c $< -o $(<:%.c=%.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
