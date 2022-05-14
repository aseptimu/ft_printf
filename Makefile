NAME = libftprintf.a

LIB_NAME = libft/libft.a

LIB_SRC = ./libft

SRCS =	analyse_params.c check_char.c ft_printf.c \
		ft_processing.c proc_integer.c proc_pointer.c \
		proc_uinteger.c proc_string.c proc_hex.c \
		utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ./includes

HEADER = includes/ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_NAME)
	cp $(LIB_NAME) ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIB_NAME) : libft ;

libft :
	$(MAKE) -C $(LIB_SRC)

bonus : $(NAME)

%.o : %.c $(HEADER)
	gcc -I $(INCLUDES) -I $(LIB_SRC) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_SRC) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C $(LIB_SRC) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all libft bonus clean fclean re 
