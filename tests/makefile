NAME = push_swap_test

INCLUDES = -I ../includes
FILES = push_swap_tools.c memory_tools.c error_handler.c \
		validation.c sort_utils.c swap_utils.c push_utils.c rotate_utils.c \
		rrotate_utils.c stack_utils.c push_swap_utils.c find_tools.c \
		sort_utils_m.c sort_utils_m2.c print_tools.c
SRC = $(FILES)
SRC_PATH = ../src/mandatory/
OBJECTS = $(SRC:%.c=%.o)
FILES_TEST = test_rotate.c
SRC_ALL = $(addprefix $(SRC_PATH), $(FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g #-fsanitize=address
# OBJ_TEST = test_rotate.c -I ./minunit/

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) test_rotate.c -c $(INCLUDES) -I .
	$(CC) $(CFLAGS) $(OBJECTS) test_rotate.o -o $(NAME)

%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -I. -c $<

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re