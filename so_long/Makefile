#####################################SO_LONG#####################################

NAME	= so_long

#####################################SRCS########################################

SRCS	+= get_map.c
SRCS	+= mains.c

INCLUDE	= -Ilibft/includes -Iinclude

LINK	= -L libft -l ft

CC		= clang
FLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

libft:
	${MAKE} -C libft

$(NAME): libft $(OBJS)
	$(CC) $(CLFAGS) $(INCLUDE) $(LINK) -o $(OBJS)

%.o: %.c
	$(CC) $(CLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all libft clean fclean re
