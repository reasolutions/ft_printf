NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_printf_utils.c
CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
		
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all