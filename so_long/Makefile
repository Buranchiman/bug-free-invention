#####################################SO_LONG#####################################

NAME	= so_long

#####################################SRCS########################################

PATH_SRCS = srcs/

SRCS	+= get_map.c
SRCS	+= checking.c
SRCS	+= direction.c
SRCS	+= travel.c
SRCS	+= init.c
SRCS	+= main.c

vpath %.c $(PATH_SRCS)

###################################OBJS#########################################

PATH_OBJS = objs
OBJS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

################################COMPILATION####################################

INCLUDE	= -Ilibft/includes -Iinclude -I /mnt/nfs/homes/wvallee/42cursus/minilibx-linux 

LINK	= libft/libft.a -L /mnt/nfs/homes/wvallee/42cursus/minilibx-linux/ -lmlx -lXext -lX11

CC		= clang
CFLAGS	= -Wall -Wextra -Werror

##################################RULES#######################################

all:  libft $(NAME)

libft:
	${MAKE} -sC libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(LINK) -g 

$(OBJS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -r $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all libft clean fclean re
