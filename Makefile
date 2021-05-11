CHECK_NAME	=	checker
PUSH_NAME	=	push_swap

FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	./includes/

CHECK_SRCS	=	$(CHECK_NAME).c								\
				$(wildcard srcs/$(CHECK_NAME)/*.c)			\
				$(wildcard Libft/*.c)

PUSH_SRCS	=	$(PUSH_NAME).c								\
				$(wildcard srcs/$(PUSH_NAME)/*.c)			\
				$(wildcard Libft/*.c)

CHECK_OBJS	=	$(CHECK_SRCS:.c=.o)

PUSH_OBJS	=	$(CHECK_SRCS:.c=.o)

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ -I $(INCLUDES)

all: $(CHECK_NAME) $(PUSH_NAME)

checker: $(CHECK_NAME)

push_swap: $(PUSH_NAME)

$(CHECK_NAME): $(CHECK_OBJS)
	gcc $(FLAGS) $(CHECK_OBJS) -o $(CHECK_NAME)

$(PUSH_NAME): $(PUSH_OBJS)
	gcc $(FLAGS) $(PUSH_OBJS) -o $(PUSH_NAME)

clean:
	rm -f $(CHECK_OBJS) $(PUSH_OBJS)

fclean: clean
	rm -f $(CHECK_NAME) $(PUSH_NAME)

re: fclean all

.PHONY: all clean flcean re bonus
