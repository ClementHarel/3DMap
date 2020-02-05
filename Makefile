##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= my_world

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c			\
	  ./src/window.c		\
	  ./src/cursor.c 		\
	  ./src/generate_map.c		\
	  ./src/change_coordinate.c	\
	  ./src/create_shape.c		\
	  ./src/button.c		\
	  ./src/choose_map.c		\
	  ./src/ystep.c			\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lc_graph_prog -lm


oui:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
