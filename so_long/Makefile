#####################################SO_LONG#####################################

NAME	= so_long

#####################################SRCS########################################

PATH_SRCS = srcs/

SRCS	+= get_map.c
SRCS	+= checking.c
SRCS	+= direction.c
SRCS	+= travel.c
SRCS	+= init.c
SRCS	+= window.c
MAIN	+= srcs/main.c

SRCS_BONUS += anim_start_bonus.c
SRCS_BONUS += anim_bonus.c
SRCS_BONUS += travel_bonus.c
MAIN_BONUS += srcs/main_bonus.c

vpath %.c $(PATH_SRCS)

###################################OBJS#########################################

PATH_OBJS = objs
OBJS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

OBJS_BONUS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_BONUS))

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
	$(CC) $(CFLAGS) -c $(MAIN) -o objs/main.o $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) objs/main.o $(INCLUDE) $(LINK) -g3 

$(OBJS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

bonus: $(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -c $(MAIN_BONUS) -o objs/main_bonus.o $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_BONUS) objs/main_bonus.o $(INCLUDE) $(LINK) -g3	

$(OBJS_BONUS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -r $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all libft clean fclean re
