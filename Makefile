GCC=gcc
FLAGS=-Werror-Wall-Wextra
SRCS=ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
NAME=libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	
.c.o : $(SRCS)
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) 