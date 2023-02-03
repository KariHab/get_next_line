NAME = get_next_line

#compile and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n
RM		=	rm -f

# Sources are all .c files
SRCS =  get_next_line.c\
		get_next_line_utils.c 


OBJS = $(SRCS:.c=.o)

#pas besoin d'une archive donc pas de make avec ar

all: $(NAME)

# clean o created
clean:
	$(RM) $(OBJS)

# clean o created and exe
fclean: clean
	$(RM) $(NAME)

re: fclean all