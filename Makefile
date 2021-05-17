NAME		=	push_swap

FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	./includes/

SRCS		=	$(NAME).c								\
				$(wildcard srcs/*.c)			\
				$(wildcard Libft/*.c)

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ -I $(INCLUDES)

all: $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re bonus
