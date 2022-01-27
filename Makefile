GCC=gcc
AR=ar
FLAGS=-Werror -Wall -Wextra
ARFLAGS=-rc
SRCS=ft_printf.c ft_printf_main_utils.c ft_printf_sub_utils.c ft_printf_length_utils.c
OBJS = $(SRCS:.c=.o)
NAME=libftprintf.a

all : $(NAME)
	
.c.o : $(SRCS)
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME) $(OBJS)
re: fclean all

.PHONY: all clean fclean re