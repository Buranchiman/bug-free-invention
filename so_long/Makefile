#####################################SO_LONG#####################################

NAME	= so_long

#####################################SRCS########################################

SRCS	+= get_map.c
SRCS	+= checking.c
SRCS	+= travel.c
SRCS	+= main.c

INCLUDE	= -Ilibft/includes -Iinclude -I /mnt/nfs/homes/wvallee/42cursus/minilibx-linux 

LINK	= libft/libft.a -L /mnt/nfs/homes/wvallee/42cursus/minilibx-linux/ -lmlx -lXext -lX11


CC		= clang
CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

all:  libft $(NAME)

libft:
	${MAKE} -sC libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(LINK)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< -g

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all libft clean fclean re
